from pyfiglet import Figlet


def main():
    s = input()

    s.split()
    print(s)

    length = len(s.split())
    print(length)

    print(f"number of args: {len(s)}")

    if len(s) == 1:
        ...

    if len(s) == 3:
        ...

if __name__ == "__main__":
    main()