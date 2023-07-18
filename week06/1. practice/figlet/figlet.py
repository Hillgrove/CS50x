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
        print("2 args")
        if text[1] not in ["-f", "--font"] and text[2] not in fonts:
            print("Usage: text [-f font] or [--font font]")
            sys.exit()
        else:
            figlet.setFont(font=random_font)
            print(figlet.renderText(text))


if __name__ == "__main__":
    main()