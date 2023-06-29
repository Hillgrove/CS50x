#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE average = round((image[i][j].rgbtRed +  image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            BYTE sepiaRed = round(fmin(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue, 255.0));
            BYTE sepiaGreen = round(fmin(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue, 255.0));
            BYTE sepiaBlue = round(fmin(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue, 255.0));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, middle = width / 2; j < middle; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a boxblur-copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Calculate blur value of pixel
    for (int i = 0; i < height; i++)
    {
        int blurredRed = 0;
        int blurredGreen = 0;
        int blurredBlue = 0;
        int divisor = 0;

        for (int j = 0; j < width; j++)
        {
            for (int k = fmax(i - 1, 0); k < fmin(i + 2, height); k++)
            {
                for (int l = fmax(j - 1, 0); l < fmin(j + 2, width); l++)
                {
                    blurredRed += image[k][l].rgbtRed;
                    blurredGreen += image[k][l].rgbtGreen;
                    blurredBlue += image[k][l].rgbtBlue;
                    divisor++;
                }
            }
            // Save average color to image
            int redtest = round(blurredRed / divisor);
            int greentest = round(blurredGreen  / divisor);
            int bluetest = round(blurredBlue / divisor);
            
            image[i][j].rgbtRed = round(blurredRed / divisor);
            image[i][j].rgbtGreen = round(blurredGreen  / divisor);
            image[i][j].rgbtBlue = round(blurredBlue / divisor);

            // Reset colors
            blurredRed = 0;
            blurredGreen = 0;
            blurredBlue = 0;
            divisor = 0;
        }

    }
    return;
}

