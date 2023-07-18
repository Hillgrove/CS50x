import random
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

    elif argc == 3 and text[1] in ["-f", "--font"] and text[2] in fonts:
        print("3 arguments")

    else:
        


if __name__ == "__main__":
    main()