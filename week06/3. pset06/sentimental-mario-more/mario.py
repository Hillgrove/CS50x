GAP = 2 * " "

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
        white_space = (height - i - 1) * ' '
        blocks = (i + 1) * '#'
        print(f"{white_space}{blocks}{GAP}{blocks}")


if __name__ == "__main__":
    main()