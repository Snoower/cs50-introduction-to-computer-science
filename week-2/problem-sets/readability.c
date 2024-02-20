#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float L = ((float) count_letters(text) / count_words(text)) * 100.00;
    float S = ((float) count_sentences(text) / count_words(text)) * 100.00;
    int index = roundf((0.0588 * L) - (0.296 * S) - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int count =
        1; // Accounts for the last word (i.e. without count=1, 'how are you' counts as two whereas 'how are you ' counts as three.)
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            while (text[i + 1] == ' ' || text[i + 1] == '\n') // Skips consecutive spaces
            {
                i++;
            }
            count += 1;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}
