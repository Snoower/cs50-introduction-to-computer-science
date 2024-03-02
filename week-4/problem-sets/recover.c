#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Correct usage: ./recover <file_name>\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    uint8_t buffer[512];
    int jpgCount = 0;
    FILE *currentFile = NULL;

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (currentFile != NULL)
            {
                fclose(currentFile);
            }

            char jpgname[8];
            sprintf(jpgname, "%03i.jpg", jpgCount);
            currentFile = fopen(jpgname, "wb");
            if (currentFile == NULL)
            {
                fclose(card);
                printf("Could not create file");
                return 1;
            }
            jpgCount++;
        }
        if (currentFile != NULL)
        {
            fwrite(buffer, 1, 512, currentFile);
        }
    }

    if (currentFile != NULL)
    {
        fclose(currentFile);
    }

    fclose(card);
    return 0;
}
