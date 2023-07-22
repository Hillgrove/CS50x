def main():
    height = int(input("Height: "))
    for i in range(height):
        print(f"{(height - i - 1) * ' '}{i * '*'}")


if __name__ == "__main__":
    main()