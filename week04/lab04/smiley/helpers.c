#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_color;
    new_color.rgbtRed = 127;
    new_color.rgbtGreen = 127;
    new_color.rgbtBlue = 127;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                image[i][j] = new_color;
            }
        }
    }

    // Change all black pixels to a color of your choosing
}
