#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Set the new color the black pixels should be changed to
    RGBTRIPLE new_color;
    new_color.rgbtRed = 47;
    new_color.rgbtGreen = 128;
    new_color.rgbtBlue = 86;

    // Iterate through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // If pixel is black, change the color to new_color
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                image[i][j] = new_color;
            }
        }
    }
}
