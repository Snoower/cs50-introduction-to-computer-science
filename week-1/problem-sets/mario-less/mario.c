#include <cs50.h>
#include <stdio.h>

int get_height();

int main(void)
{
    int height = get_height();
    for (int row = 0; row < height; row++)
    {
        for (int space = row + 1; space < height; space++)
        {
            printf(" ");
        }

        for (int block = height + row + 1; block > height; block--)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height()
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}
