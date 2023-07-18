import sys

def main():
    greeting = input("Greeting: ").lower()

    if greeting[1] == "hello" and len(sys.argv) == 2:
        print("$0")
    elif greeting[0] == "h":
        print("$20")
    else:
        print("$100")


main()