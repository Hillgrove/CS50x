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

    

    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "GET":
        return render_template("buy.html")

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
    funds = db.execute(
        "SELECT cash FROM users WHERE id = ?", session["user_id"]
    )[0]['cash']

    if funds < total_cost:
        return apology("Not enough funds", 400)

    #Updating database with purchase
    try:
        db.execute(
            "INSERT INTO portfolio (user_id, symbol, price, amount) VALUES (?, ?, ?, ?)", session["user_id"], symbol, price, amount
        )
    except Exception:
        return apology("an error occured while registering", 500)

    #Remove price from user table
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
    return apology("TODO")


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
    price = usd(lookup(symbol)['price'])

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
    return apology("TODO")
