#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc == 2 && strspn(argv[1], "0123456789") == strlen(argv[1]))
    {
        string plaintext = get_string("plaintext:  ");
        int key = atoi(argv[1]);
        int l = strlen(plaintext);
        char ciphertext[l + 1];

        for (int i = 0; i < l; i++)
        {
            ciphertext[i] = rotate(plaintext[i], key);
        }
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        return ((c - 'A' + n) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' + n) % 26) + 'a';
    }
    else
    {
        return c;
    }
}
