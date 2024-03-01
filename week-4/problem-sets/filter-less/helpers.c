#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen +
                               image[i][j].rgbtBlue) /
                              3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue =
                avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed +
                                 .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed +
                                   .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed +
                                  .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);
            if (sepiaRed <= 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                RGBTRIPLE temporary_image[i][j];
                temporary_image[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temporary_image[i][j];
            }
        }
        else if (width % 2 != 0)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                RGBTRIPLE temporary_image[i][j];
                temporary_image[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temporary_image[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0) // top left pixel
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_right = image[i][j + 1];
                RGBTRIPLE pixel_bottom = image[i + 1][j];
                RGBTRIPLE pixel_bottom_right = image[i + 1][j + 1];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_right.rgbtRed +
                           pixel_bottom.rgbtRed + pixel_bottom_right.rgbtRed) /
                          4.0);
                copy[i][j].rgbtGreen = round(
                    (pixel.rgbtGreen + pixel_right.rgbtGreen +
                     pixel_bottom.rgbtGreen + pixel_bottom_right.rgbtGreen) /
                    4.0);
                copy[i][j].rgbtBlue = round(
                    (pixel.rgbtBlue + pixel_right.rgbtBlue +
                     pixel_bottom.rgbtBlue + pixel_bottom_right.rgbtBlue) /
                    4.0);
            }
            else if (i == 0 && j == (width - 1)) // top right pixel
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_left = image[i][j - 1];
                RGBTRIPLE pixel_bottom = image[i + 1][j];
                RGBTRIPLE pixel_bottom_left = image[i + 1][j - 1];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_left.rgbtRed +
                           pixel_bottom.rgbtRed + pixel_bottom_left.rgbtRed) /
                          4.0);
                copy[i][j].rgbtGreen = round(
                    (pixel.rgbtGreen + pixel_left.rgbtGreen +
                     pixel_bottom.rgbtGreen + pixel_bottom_left.rgbtGreen) /
                    4.0);
                copy[i][j].rgbtBlue =
                    round((pixel.rgbtBlue + pixel_left.rgbtBlue +
                           pixel_bottom.rgbtBlue + pixel_bottom_left.rgbtBlue) /
                          4.0);
            }
            else if (i == (height - 1) && j == 0) // bottom left pixel
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_right = image[i][j + 1];
                RGBTRIPLE pixel_top = image[i - 1][j];
                RGBTRIPLE pixel_top_right = image[i - 1][j + 1];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_right.rgbtRed +
                           pixel_top.rgbtRed + pixel_top_right.rgbtRed) /
                          4.0);
                copy[i][j].rgbtGreen =
                    round((pixel.rgbtGreen + pixel_right.rgbtGreen +
                           pixel_top.rgbtGreen + pixel_top_right.rgbtGreen) /
                          4.0);
                copy[i][j].rgbtBlue =
                    round((pixel.rgbtBlue + pixel_right.rgbtBlue +
                           pixel_top.rgbtBlue + pixel_top_right.rgbtBlue) /
                          4.0);
            }
            else if (i == (height - 1) && j == (width - 1)) // bottom right
                                                            // pixel
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_left = image[i][j - 1];
                RGBTRIPLE pixel_top = image[i - 1][j];
                RGBTRIPLE pixel_top_left = image[i - 1][j - 1];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_left.rgbtRed +
                           pixel_top.rgbtRed + pixel_top_left.rgbtRed) /
                          4.0);
                copy[i][j].rgbtGreen =
                    round((pixel.rgbtGreen + pixel_left.rgbtGreen +
                           pixel_top.rgbtGreen + pixel_top_left.rgbtGreen) /
                          4.0);
                copy[i][j].rgbtBlue =
                    round((pixel.rgbtBlue + pixel_left.rgbtBlue +
                           pixel_top.rgbtBlue + pixel_top_left.rgbtBlue) /
                          4.0);
            }
            else if (i == 0) // top middle pixel
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_left = image[i][j - 1];
                RGBTRIPLE pixel_bottom_left = image[i + 1][j - 1];
                RGBTRIPLE pixel_bottom = image[i + 1][j];
                RGBTRIPLE pixel_bottom_right = image[i + 1][j + 1];
                RGBTRIPLE pixel_right = image[i][j + 1];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_left.rgbtRed +
                           pixel_bottom_left.rgbtRed + pixel_bottom.rgbtRed +
                           pixel_bottom_right.rgbtRed + pixel_right.rgbtRed) /
                          6.0);
                copy[i][j].rgbtGreen = round(
                    (pixel.rgbtGreen + pixel_left.rgbtGreen +
                     pixel_bottom_left.rgbtGreen + pixel_bottom.rgbtGreen +
                     pixel_bottom_right.rgbtGreen + pixel_right.rgbtGreen) /
                    6.0);
                copy[i][j].rgbtBlue =
                    round((pixel.rgbtBlue + pixel_left.rgbtBlue +
                           pixel_bottom_left.rgbtBlue + pixel_bottom.rgbtBlue +
                           pixel_bottom_right.rgbtBlue + pixel_right.rgbtBlue) /
                          6.0);
            }
            else if (j == 0) // left middle pixel
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_top = image[i - 1][j];
                RGBTRIPLE pixel_top_right = image[i - 1][j + 1];
                RGBTRIPLE pixel_right = image[i][j + 1];
                RGBTRIPLE pixel_bottom_right = image[i + 1][j + 1];
                RGBTRIPLE pixel_bottom = image[i + 1][j];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_top.rgbtRed +
                           pixel_top_right.rgbtRed + pixel_right.rgbtRed +
                           pixel_bottom_right.rgbtRed + pixel_bottom.rgbtRed) /
                          6.0);
                copy[i][j].rgbtGreen = round(
                    (pixel.rgbtGreen + pixel_top.rgbtGreen +
                     pixel_top_right.rgbtGreen + pixel_right.rgbtGreen +
                     pixel_bottom_right.rgbtGreen + pixel_bottom.rgbtGreen) /
                    6.0);
                copy[i][j].rgbtBlue = round(
                    (pixel.rgbtBlue + pixel_top.rgbtBlue +
                     pixel_top_right.rgbtBlue + pixel_right.rgbtBlue +
                     pixel_bottom_right.rgbtBlue + pixel_bottom.rgbtBlue) /
                    6.0);
            }
            else if (j == width - 1) // right middle pixel
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_top = image[i - 1][j];
                RGBTRIPLE pixel_top_left = image[i - 1][j - 1];
                RGBTRIPLE pixel_left = image[i][j - 1];
                RGBTRIPLE pixel_bottom_left = image[i + 1][j - 1];
                RGBTRIPLE pixel_bottom = image[i + 1][j];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_top.rgbtRed +
                           pixel_top_left.rgbtRed + pixel_left.rgbtRed +
                           pixel_bottom_left.rgbtRed + pixel_bottom.rgbtRed) /
                          6.0);
                copy[i][j].rgbtGreen = round(
                    (pixel.rgbtGreen + pixel_top.rgbtGreen +
                     pixel_top_left.rgbtGreen + pixel_left.rgbtGreen +
                     pixel_bottom_left.rgbtGreen + pixel_bottom.rgbtGreen) /
                    6.0);
                copy[i][j].rgbtBlue =
                    round((pixel.rgbtBlue + pixel_top.rgbtBlue +
                           pixel_top_left.rgbtBlue + pixel_left.rgbtBlue +
                           pixel_bottom_left.rgbtBlue + pixel_bottom.rgbtBlue) /
                          6.0);
            }
            else if (i == height - 1) // bottom middle
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_left = image[i][j - 1];
                RGBTRIPLE pixel_top_left = image[i - 1][j - 1];
                RGBTRIPLE pixel_top = image[i - 1][j];
                RGBTRIPLE pixel_top_right = image[i - 1][j + 1];
                RGBTRIPLE pixel_right = image[i][j + 1];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_left.rgbtRed +
                           pixel_top_left.rgbtRed + pixel_top.rgbtRed +
                           pixel_top_right.rgbtRed + pixel_right.rgbtRed) /
                          6.0);
                copy[i][j].rgbtGreen =
                    round((pixel.rgbtGreen + pixel_left.rgbtGreen +
                           pixel_top_left.rgbtGreen + pixel_top.rgbtGreen +
                           pixel_top_right.rgbtGreen + pixel_right.rgbtGreen) /
                          6.0);
                copy[i][j].rgbtBlue =
                    round((pixel.rgbtBlue + pixel_left.rgbtBlue +
                           pixel_top_left.rgbtBlue + pixel_top.rgbtBlue +
                           pixel_top_right.rgbtBlue + pixel_right.rgbtBlue) /
                          6.0);
            }
            else
            {
                RGBTRIPLE pixel = image[i][j];
                RGBTRIPLE pixel_top_left = image[i - 1][j - 1];
                RGBTRIPLE pixel_top = image[i - 1][j];
                RGBTRIPLE pixel_top_right = image[i - 1][j + 1];
                RGBTRIPLE pixel_left = image[i][j - 1];
                RGBTRIPLE pixel_right = image[i][j + 1];
                RGBTRIPLE pixel_bottom = image[i + 1][j];
                RGBTRIPLE pixel_bottom_left = image[i + 1][j - 1];
                RGBTRIPLE pixel_bottom_right = image[i + 1][j + 1];

                copy[i][j].rgbtRed =
                    round((pixel.rgbtRed + pixel_top_left.rgbtRed +
                           pixel_top.rgbtRed + pixel_top_right.rgbtRed +
                           pixel_left.rgbtRed + pixel_right.rgbtRed +
                           pixel_bottom.rgbtRed + pixel_bottom_left.rgbtRed +
                           pixel_bottom_right.rgbtRed) /
                          9.0);
                copy[i][j].rgbtGreen = round(
                    (pixel.rgbtGreen + pixel_top_left.rgbtGreen +
                     pixel_top.rgbtGreen + pixel_top_right.rgbtGreen +
                     pixel_left.rgbtGreen + pixel_right.rgbtGreen +
                     pixel_bottom.rgbtGreen + pixel_bottom_left.rgbtGreen +
                     pixel_bottom_right.rgbtGreen) /
                    9.0);
                copy[i][j].rgbtBlue =
                    round((pixel.rgbtBlue + pixel_top_left.rgbtBlue +
                           pixel_top.rgbtBlue + pixel_top_right.rgbtBlue +
                           pixel_left.rgbtBlue + pixel_right.rgbtBlue +
                           pixel_bottom.rgbtBlue + pixel_bottom_left.rgbtBlue +
                           pixel_bottom_right.rgbtBlue) /
                          9.0);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
