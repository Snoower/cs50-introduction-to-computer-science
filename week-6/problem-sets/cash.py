def main():
    change = 0
    quarter = 25
    dime = 10
    nickel = 5
    penny = 1

    change_owed = get_change()
    remainder = change_owed % quarter
    change += change_owed // quarter
    if remainder != 0:
        change += remainder // dime
        remainder = remainder % dime
        if remainder != 0:
            change += remainder // nickel
            remainder = remainder % nickel
            if remainder != 0:
                change += remainder // penny
                remainder = remainder % penny
    print(int(change))


def get_change():
    while True:
        c = input("Change Owed: ")
        if c.replace(".", "", 1).isdigit():
            c = float(c)
            if c >= 0:
                return int(c * 100)


if __name__ == "__main__":
    main()
