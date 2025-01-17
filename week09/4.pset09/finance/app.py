import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    portfolio = db.execute("""
                           SELECT symbol, SUM(amount) AS [shares]
                           FROM portfolio
                           WHERE user_id = ?
                           GROUP BY symbol""", session['user_id']
                           )

    # Adds current price for each stock and their total value
    for stock in portfolio:
        stock['price'] = lookup(stock['symbol'])['price']
        stock['total'] = stock['price'] * stock['shares']

    cash = db.execute(
        "SELECT cash from users where id = ?", session['user_id']
    )[0]['cash']

    # Calculate total value of portfolio + liquidity
    total = cash
    for stock in portfolio:
        total += stock['price'] * stock['shares']

    return render_template("index.html", portfolio=portfolio, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    symbol = request.args.get("symbol", "").upper()
    if request.method == "GET":
        return render_template("buy.html", symbol=symbol)

    # Checking inputs
    symbol = request.form.get("symbol")
    if not symbol:
        return apology("Missing symbol", 400)

    if lookup(symbol) == None:
        return apology("Invalid symbol", 400)

    amount = request.form.get("shares")
    if not amount:
        return apology("Missing shares", 400)

    try:
        amount = int(amount)
        if amount < 0:
            return apology("Shares must be positive", 400)

    except ValueError:
        return apology("Shares not a valid number", 400)

    # Ensuring enough funds
    price = lookup(symbol)['price']
    total_cost = price * amount
    funds = db.execute("""
                       SELECT cash
                       FROM users
                       WHERE id = ?""", session["user_id"]
                       )[0]['cash']

    if funds < total_cost:
        return apology("Not enough funds", 400)

    # Updating database with purchase
    exists = db.execute("""
                        SELECT *
                        FROM portfolio
                        WHERE user_id = ?
                        AND symbol = ?""", session['user_id'], symbol)

    if exists:
        try:
            db.execute("""
                       UPDATE portfolio
                       SET amount = amount + ?
                       WHERE user_id = ?
                       AND symbol = ?""", amount, session['user_id'], symbol)
        except Exception:
            return apology("an error occured while registering", 500)

    else:
        try:
            db.execute("""
                       INSERT INTO portfolio (user_id, symbol, amount)
                       VALUES (?, ?, ?)""", session["user_id"], symbol, amount
                       )
        except Exception:
            return apology("an error occured while registering", 500)

    # Updating history
    db.execute("""
               INSERT INTO history (user_id, symbol, price, amount)
               VALUES (?, ?, ?, ?)""", session['user_id'], symbol, price, amount
               )

    # Remove price from user table
    db.execute("""
               UPDATE users
               SET cash = cash - ?
               WHERE id = ?""", total_cost, session["user_id"]
               )

    flash('Bought!')
    # Redirect user to home page
    return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    history = db.execute("""
                         SELECT id, symbol, price, amount, date
                         FROM history
                         WHERE user_id = ?
                         ORDER BY id""", session['user_id'])

    print(f"""== DEBUG ==\n
              {history}\n
              == DEBUG ==""")

    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        flash('You were successfully logged in')
        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "GET":
        return render_template("quote.html")

    # POST method processing
    symbol = request.form.get("symbol").upper()

    try:
        price = usd(lookup(symbol)['price'])

    except TypeError:
        return apology("Invalid symbol", 400)

    return render_template("quoted.html", symbol=symbol, price=price)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "GET":
        return render_template("register.html")

    # POST method processing
    username = request.form.get("username")
    if not username:
        return apology("must provide username", 400)

    password = request.form.get("password")
    confirmation = request.form.get("confirmation")
    if not password:
        return apology("must provide password", 400)
    if not confirmation:
        return apology("must provide confirmation", 400)
    if not password == confirmation:
        return apology("password and confirmation must be the same", 400)

    # Check if username already exists
    user_check = db.execute(
        "SELECT * FROM users WHERE username = ?", username
    )
    if user_check:
        return apology("username already exsits", 400)

    # Checks passed - add new user
    hash = generate_password_hash(password)

    try:
        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)", username, hash
        )
    except Exception:
        return apology("an error occured while registering", 500)

    flash('User successfully created')
    # redirect user to login after registering
    return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    symbols = db.execute("""
                        SELECT DISTINCT symbol
                        FROM portfolio
                        WHERE user_id = ?""", session['user_id'])

    symbol_list = [dic['symbol'].upper() for dic in symbols]
    selected_symbol = request.args.get("symbol", "").upper()

    # GET method
    if request.method == "GET":
        return render_template("sell.html", symbols=symbol_list, selected_symbol=selected_symbol)

    # POST method
    symbol = request.form.get("symbol")
    amount_to_sell = request.form.get("shares")
    amount_in_portfolio = db.execute("""
                        SELECT amount
                        FROM portfolio
                        WHERE user_id = ?
                        AND symbol = ?""", session['user_id'], symbol)

    # Check if the result is not empty
    if amount_in_portfolio[0]['amount'] is not None:
        amount_in_portfolio = amount_in_portfolio[0]['amount']
    else:
        amount_in_portfolio = 0

    if symbol == None:
        return apology("Missing symbol", 400)

    if symbol not in symbol_list:
        return apology("Stock not owned", 400)

    try:
        amount_to_sell = int(amount_to_sell)
    except ValueError:
        return apology("Shares not valid", 400)

    if amount_to_sell == "":
        return apology("Missing shares", 400)

    if amount_to_sell < 0:
        return apology("Shares must be positive", 400)

    if amount_to_sell > amount_in_portfolio:
        return apology("Too many shares", 400)

    # All checks completed - update database
    current_price = lookup(symbol)['price']
    sell_price = current_price * amount_to_sell

    # Add funds to DB
    db.execute("""
               UPDATE users
               SET cash = cash + ?
               WHERE id = ?""", sell_price, session['user_id'])

    # Remove stocks from portfolio
    if amount_to_sell == amount_in_portfolio:
        db.execute("""
                    DELETE
                    FROM portfolio
                    WHERE user_id = ?
                    AND symbol = ?""", session['user_id'], symbol)
    else:
        db.execute("""
                    UPDATE portfolio
                    SET amount = amount - ?
                    WHERE user_id = ?
                    AND symbol = ?""", amount_to_sell, session['user_id'], symbol)

    # Add sale to history
    db.execute("""
            INSERT INTO history (user_id, symbol, price, amount)
            VALUES (?, ?, ?, ?)""", session['user_id'], symbol, current_price, -amount_to_sell)

    flash("Share sold")
    return redirect("/")
