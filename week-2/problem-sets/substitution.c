#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char subsitute(char c, string key);

int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        string key = argv[1];
        for (int i = 0; i < 26; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Key must contain only alphabetic characters.\n");
                return 1;
            }

            for (int j = i + 1; j < 26; j++)
            {
                if (key[i] == key[j])
                {
                    printf("Key must contain unique characters.\n");
                    return 1;
                }
            }
        }
        string plaintext = get_string("plaintext:  ");
        int l = strlen(plaintext);
        char ciphertext[l + 1];
        for (int i = 0; i < l; i++)
        {
            ciphertext[i] = subsitute(plaintext[i], key);
        }
        ciphertext[l] = '\0';
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else if (argc == 2 && strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

char subsitute(char c, string key)
{
    if (isupper(c))
    {
        if (c >= 'A' && c <= 'Z')
        {
            return toupper(key[c - 'A']);
        }
    }
    else if (islower(c))
    {
        if (c >= 'a' && c <= 'z')
        {
            return tolower(key[c - 'a']);
        }
    }
    return c;
}
