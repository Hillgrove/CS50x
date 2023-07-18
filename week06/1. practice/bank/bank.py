def main():
    greeting = input("Greeting: ").lower()
    first_word = greeting.split()[0]
    print(f"first word is: {first_word}")

    if greeting[:5] == "hello":
        print("$0")
    elif greeting[:1] == "h":
        print("$20")
    else:
        print("$100")


if __name__ == "__main__":
    main()