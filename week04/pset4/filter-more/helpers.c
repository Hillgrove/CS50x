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
    RGBTRIPLE copy[height][width];
    int blurredRed = 0;
    int blurredGreen = 0;
    int blurredBlue = 0;
    float divisor = 0.0;

    // Create a copy of image
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
    RGBTRIPLE copy[height][width];
    int GxKernel[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
        };
    int GyKernel[3][3] = {
        {-1, 2, -1},
        {0, 0, 0},
        {1, 2, 1}
        };
    RGBTRIPLE Gx;
    RGBTRIPLE Gy;

    // Create copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Calculate edge value of pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k < 0 || k > height + 1 || l < 0 || l > width + 1)
                    {
                        Gx.rgbtRed += 0;
                        Gx.rgbtGreen += 0;
                        Gx.rgbtlue += 0;
                    }

                    else
                    {

                    }
                }
            }

        }
    }
    return;
}
