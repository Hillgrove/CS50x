import random
import sys
from pyfiglet import Figlet


def main():
    text = input("Input: ").strip()
    argc = len(sys.argv)
    print(sys.argv)
    print(argc)

    figlet = Figlet()
    fonts = figlet.getFonts()


    if argc == 1:
        random_font = random.choice(fonts)
        figlet.setFont(font=random_font)
        print("zero argument")
        print(figlet.renderText(text))

    elif argc == 3:
        if text[1] not in ["-f", "--font"] and text[2] not in fonts:
            print("Usage: text [-f font] or [--font font]")
            sys.exit()
        else:
            print("3 arguments and correct arguments")


if __name__ == "__main__":
    main()