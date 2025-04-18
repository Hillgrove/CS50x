from flask import Flask, render_template, request

app = Flask(__name__)

COLORS = [
    {"red": "Harvard Crimson"},
    {"blue": "Yale Blue"}
    ]


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html", colors=COLORS)
    else:
        print("Form submitted!")
        color = request.form.get("color")
        return render_template("color.html", color=color)
