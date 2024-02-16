#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long ccNumber = get_long("Number: ");
    int firstSum = 0;
    int num = 0;
    int remainder = 0;
    int secondSum = 0;
    long temp = ccNumber;
    while (temp > 0)
    {
        num = ((temp / 10) % 10) * 2;
        while (num > 0)
        {
            remainder = num % 10;
            firstSum += remainder;
            num = num / 10;
        }
        temp = temp / 100;
    }
    remainder = 0;
    temp = ccNumber;

    while (temp > 0)
    {
        remainder = temp % 10;
        secondSum += remainder;
        temp = temp / 100;
    }
    if ((firstSum + secondSum) % 10 == 0)
    {
        if ((ccNumber >= 340000000000000 && ccNumber < 350000000000000) ||
            (ccNumber >= 370000000000000 && ccNumber < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (ccNumber >= 5100000000000000 && ccNumber < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((ccNumber >= 4000000000000 && ccNumber < 5000000000000) ||
                 (ccNumber >= 4000000000000000 && ccNumber < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}
