#include <cs50.h>
#include <stdio.h>

int get_change();

int main(void)
{
    int change = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    int change_owed = get_change();

    int remainder = change_owed % quarter;
    change += change_owed / quarter;
    if (remainder != 0)
    {
        change += remainder / dime;
        remainder = remainder % dime;

        if (remainder != 0)
        {
            change += remainder / nickel;
            remainder = remainder % nickel;

            if (remainder != 0)
            {
                change += remainder / penny;
                remainder = remainder % penny;
            }
        }
    }
    printf("%i\n", change);
}

int get_change()
{
    int c;
    do
    {
        c = get_int("Change Owed: ");
    }
    while (c < 1);
    return c;
}
