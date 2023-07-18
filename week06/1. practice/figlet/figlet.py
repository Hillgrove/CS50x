import random
import sys
from pyfiglet import Figlet


def main():
    text = input("Input: ").strip()
    argc = len(sys.argv) - 1

    figlet = Figlet()
    fonts = figlet.getFonts()

    if argc == 0:
        random_font = random.choice(fonts)
        figlet.setFont(font=random_font)
        print(f"Output: \n{figlet.renderText(text)}")

    elif argc == 2:
        if text[1] not in ["-f", "--font"] and text[2] not in fonts:
            print("Invalid usage")
            sys.exit(1)
        else:
            figlet.setFont(font=text[1])
            print(figlet.renderText(text[2]))


if __name__ == "__main__":
    main()