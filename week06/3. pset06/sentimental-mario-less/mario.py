def main():
    while True:
        height = int(input("Height: "))
        if 0 < height < 9:
            break

    for i in range(height):
        print(f"{(height - i - 1) * ' '}{(i + 1) * '#'}")


if __name__ == "__main__":
    main()