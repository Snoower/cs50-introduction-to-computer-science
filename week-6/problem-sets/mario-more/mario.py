def main():
    height = int(get_height())
    for row in range(height):
        for space in range(row + 1, height):
            print(" ", end="")
        for block in range(height + row + 1, height, -1):
            print("#", end="")
        print("  ", end="")
        for block in range(height + row + 1, height, -1):
            print("#", end="")
        print()


def get_height():
    h = 0
    while not str(h).isdigit() or int(h) < 1 or int(h) > 8:
        h = input("Height: ")
    return h


if __name__ == "__main__":
    main()
