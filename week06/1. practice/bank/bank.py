def main():
    greeting = input("Greeting: ").lower()


    if greeting[:5] == "hello":
        print("$0")
    elif greeting[:1] == "h":
        print("$20")
    else:
        print("$100")


if __name__ == "__main__":
    main()
