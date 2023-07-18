import pyfiglet
import sys


def main():
    text = input("Input: ").trim()

    print(f"number of args: {len(sys.argv)}")

    if len(sys.argv) == 1:
        ...

    if len(sys.argv) == 3:
        ...

if __name__ == "__main__":
    main()