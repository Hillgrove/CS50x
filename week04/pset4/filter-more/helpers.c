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
    RGBTRIPLE kernel[3][3];

    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
        };
    int Gy[3][3] = {
        {-1, 2, -1},
        {0, 0, 0},
        {1, 2, 1}
        };

    int GxRed = 0, GxGreen = 0, GxBlue = 0;
    int GyRed = 0, GyGreen = 0, GyBlue = 0;


    // Create copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Copy RGB values of a 3x3 grid surrounding pixel to a new 2D array.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = - 1; k < 2; k++)
            {
                for (int l = - 1; l < 2; l++)
                {
                    if (i + k < 0 || i + k > height || j + l < 0 || j + l > width)
                    {
                        kernel[k + 1][l + 1].rgbtRed = 0;
                        kernel[k + 1][l + 1].rgbtGreen = 0;
                        kernel[k + 1][l + 1].rgbtBlue = 0;
                    }

                    else
                    {
                        kernel[k + 1][l + 1] = copy[i + k][j + l];
                    }
                }
            }

            // Calculate Gx and Gy values for a single pixel
            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    GxRed += kernel[m][n].rgbtRed * Gx[m][n];
                    GxGreen += kernel[m][n].rgbtGreen * Gx[m][n];
                    GxBlue += kernel[m][n].rgbtBlue * Gx[m][n];

                    GyRed += kernel[m][n].rgbtRed * Gy[m][n];
                    GyGreen += kernel[m][n].rgbtGreen * Gy[m][n];
                    GyBlue += kernel[m][n].rgbtBlue * Gy[m][n];
                }
            }

            int a = fmin(255, round(sqrt(pow(GxRed, 2) + pow(GyRed, 2))));
            int b = fmin(255, round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2))));
            int c = fmin(255, round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2))));

            image[i][j].rgbtRed = a;
            image[i][j].rgbtGreen = b;
            image[i][j].rgbtBlue = c;

            GxRed = 0, GxGreen = 0, GxBlue = 0;
            GyRed = 0, GyGreen = 0, GyBlue = 0;

        }
    }
    return;
}
