import random
import sys
from pyfiglet import Figlet


def main():
    print(len(sys.argv) - 1)
    text = input("Input: ").strip()
    argc = len(sys.argv) - 1


    figlet = Figlet()
    fonts = figlet.getFonts()

    if argc == 0:
        print(argc)
        random_font = random.choice(fonts)
        figlet.setFont(font=random_font)
        print(f"Output: \n{figlet.renderText(text)}")

    elif argc == 2:
        print(argc)
        if sys.argv[1] not in ["-f", "--font"] and sys-argv[2] not in fonts:
            print("Invalid usage")
            sys.exit(1)
        else:
            figlet.setFont(font=text[1])
            print(figlet.renderText(text[2]))


if __name__ == "__main__":
    main()