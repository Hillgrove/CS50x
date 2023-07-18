import random
import sys
from pyfiglet import Figlet


def main():
    text = input("Input: ").strip().split()
    argc = len(text)

    figlet = Figlet()
    fonts = figlet.getFonts()


    if argc == 1:
        random_font = random.choice(fonts)
        figlet.setFont(font=random_font)
        print("zero argument")
        # print(figlet.renderText(text))

    elif argc == 3:
        if text[1] not in ["-f", "--font"] and text[2] not in fonts:
            print("3 arguments but wrong arguments")
            sys.exit()
        else:
            print("3 arguments and correct arguments")


if __name__ == "__main__":
    main()