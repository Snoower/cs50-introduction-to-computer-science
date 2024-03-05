def main():
    ccNumber = int(input("Number: "))
    firstSum = 0
    num = 0
    remainder = 0
    secondSum = 0
    temp = ccNumber
    while temp > 0:
        num = ((temp // 10) % 10) * 2
        while num > 0:
            remainder = num % 10
            firstSum += remainder
            num = num // 10
        temp = temp // 100
    remainder = 0
    temp = ccNumber
    while temp > 0:
        remainder = temp % 10
        secondSum += remainder
        temp = temp // 100
    if (((firstSum+secondSum) % 10) == 0):
        if ((340000000000000 <= ccNumber < 350000000000000) or
                (370000000000000 <= ccNumber < 380000000000000)):
            print("AMEX\n")
        elif (5100000000000000 <= ccNumber < 5600000000000000):
            print("MASTERCARD\n")
        elif ((4000000000000 <= ccNumber < 5000000000000) or
              (4000000000000000 <= ccNumber < 5000000000000000)):
            print("VISA\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")


if __name__ == "__main__":
    main()
