def main():
    greeting = input("Greeting: ").lower()
    first_word = greeting.split()[0]

    if first_word == "hello":
        print("$0")
    elif first_word[:1] == "h":
        print("$20")
    else:
        print("$100")


if __name__ == "__main__":
    main()