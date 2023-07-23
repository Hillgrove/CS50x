from cs50 import get_float

QUARTER = 25
DIME = 10
NICKLE = 5
PENNY = 1


def main():
    cents = int(get_owed() * 100)
    coins = 0

    coins += cents // QUARTER
    cents = cents % QUARTER

    coins += cents // DIME
    cents = cents % DIME

    coins += cents // NICKLE
    cents = cents % NICKLE

    coins += cents

    print(coins)


def get_owed():
    while True:
        owed = get_float("Change owed: ")
        if owed > 0:
            break
    
    return owed


if __name__ == "__main__":
    main()