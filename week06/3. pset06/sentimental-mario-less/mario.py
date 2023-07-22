def main():
    while True:
        try:
            height = int(input("Height: "))
        except EOFError:
            print()
            exit()
        except:
            print("Please input an integer between 0 and 9.")
        else:
            if 0 < height < 9:
                break

    for i in range(height):
        print(f"{(height - i - 1) * ' '}{(i + 1) * '#'}")


if __name__ == "__main__":
    main()