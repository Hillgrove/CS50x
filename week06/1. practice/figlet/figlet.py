import random
import sys
from pyfiglet import Figlet


def main():

    # Check for correct input
    argc = len(sys.argv) - 1

    if argc not in [0, 2]:
        print("Invalid usage")
        sys.exit(1)

    if sys.argv[1] not in ["-f", "--font"] and sys-argv[2] not in fonts:
        print("Invalid usage")
        sys.exit(1)

    # Initialize Figlet module
    figlet = Figlet()
    fonts = figlet.getFonts()

    # Get input from user
    text = input("Input: ").strip()

    if argc == 0:
        print(argc)
        random_font = random.choice(fonts)
        figlet.setFont(font=random_font)
        print(f"Output: \n{figlet.renderText(text)}")

    else:
        figlet.setFont(font=text[1])
        print(figlet.renderText(text[2]))


if __name__ == "__main__":
    main()