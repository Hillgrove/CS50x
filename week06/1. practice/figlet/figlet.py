from pyfiglet import Figlet


def main():
    text = input("Input: ").strip()

    argc = len(text.split())

    print(f"number of args: {argc}")

    if len(text) == 1:
        ...

    if len(text) == 3:
        ...

if __name__ == "__main__":
    main()