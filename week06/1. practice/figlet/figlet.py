import random
import sys
from pyfiglet import Figlet


def main():

    # Initialize Figlet module
    figlet = Figlet()
    fonts = figlet.getFonts()

    # Check for correct input
    argc = len(sys.argv) - 1

    if argc not in [0, 2]:
        print("Invalid usage")
        sys.exit(1)

    if sys.argv[1] not in ["-f", "--font"] or sys.argv[2] not in fonts:
        print("Invalid usage")
        sys.exit(1)

    # Get input from user
    text = input("Input: ").strip()

    # Set font
    if argc == 0:
        print(argc)
        random_font = random.choice(fonts)
        figlet.setFont(font=random_font)

    else:
        figlet.setFont(font=sys.argv[2])

    # Print ASCII text
    print(f"Output: \n{figlet.renderText(text)}")


if __name__ == "__main__":
    main()