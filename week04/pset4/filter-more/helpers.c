#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

RGBTRIPLE calcGx(*RGBTRIPLE copy, int i, int j);

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
        float divisor = 0.0;

        for (int j = 0; j < width; j++)
        {
            for (int k = fmax(i - 1, 0); k < fmin(i + 2, height); k++)
            {
                for (int l = fmax(j - 1, 0); l < fmin(j + 2, width); l++)
                {
                    blurredRed += copy[k][l].rgbtRed;
                    blurredGreen += copy[k][l].rgbtGreen;
                    blurredBlue += copy[k][l].rgbtBlue;
                    divisor++;
                }
            }
            // Save average color to image
            image[i][j].rgbtRed = round(blurredRed / divisor);
            image[i][j].rgbtGreen = round(blurredGreen  / divisor);
            image[i][j].rgbtBlue = round(blurredBlue / divisor);

            // Reset colors
            blurredRed = 0;
            blurredGreen = 0;
            blurredBlue = 0;
            divisor = 0.0;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE Gx;
    RGBTRIPLE Gy;
    RGBTRIPLE copy[height][width];

    // Create copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Traverse image by iRow and iCol
    for (int iRow = 0; iRow < height; iRow++)
    {
        for (int iCol = 0; iCol < width; iCol++)
        {
            Gx = calcGx(copy, i, j);
            Gy = calcGy(copy, i, j);
        }
    }
    return;
}

// Calculate Gx values
RGBTRIPLE calcGx(*copy, int i, int j)
// Traverse the 3x3 grid by gRow and gCol
for (int gRow = 0; gRow < 2; gRow++)
{
    for (int gCol = 0; gCol < 2; gCol++)
    {

    }
}