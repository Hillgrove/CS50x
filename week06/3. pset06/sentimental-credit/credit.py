def main():
    cardnumber = input("Number: ")

    if not valid_checksum(cardnumber):
        print("INVALID")
    else:
        print(distributor(cardnumber))


"""
Multiply every other digit by 2, starting with the number’s second-to-last digit,
and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is
congruent to 0), the number is valid!
"""


def valid_checksum(cardnumber):
    length = len(cardnumber)
    checksum = 0

    for i in range(length):
        if (length - i) % 2 == 0:
            temp = int(cardnumber[i]) * 2
            checksum += (temp % 10) + (temp // 10)
        else:
            checksum += int(cardnumber[i])

    if checksum % 10 == 0:
        return True
    else:
        return False


def distributor(cardnumber):
    length = len(cardnumber)

    if length == 15 and cardnumber[:2] in ["34",    "37"]:
        return "AMEX"
    elif length == 16 and cardnumber[:2] in ["51", "52", "53", "54", "55"]:
        return "MASTERCARD"
    elif length in [13, 16] and cardnumber[:1] == "4":
        return "VISA"
    else:
        return "INVALID"


if __name__ == "__main__":
    main()