def main():
    greeting = input("Greeting: ").lower()

    if greeting[0] == "hello":
        print("$0")
    elif greeting[0] == "h":
        print("$20")
    else:
        print("$100")


main()