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
        print(figlet.renderText(text))

    if argc == 3:
        ...

if __name__ == "__main__":
    main()