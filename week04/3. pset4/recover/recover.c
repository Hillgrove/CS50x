#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef uint8_t BYTE;
int const BLOCK_SIZE = 512;

bool new_image(BYTE buffer[]);


int main(int argc, char *argv[])
{
    // Check if CLI arguments are correct
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Remember filename
    char *raw_file = argv[1];

    // Open source file
    FILE *inptr = fopen(raw_file, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", raw_file);
        return 1;
    }


    BYTE buffer[BLOCK_SIZE];
    int image_count = 0;
    FILE *img = NULL;
    char filename[8];
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // If new image is found
        if (new_image(buffer))
        {
            // Create a new file with "filename" as name and write first BLOCK_SIZE to it
            if (image_count == 0)
            {
                sprintf(filename, "%03i.jpg", image_count);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                image_count++;

            }
            // Close old file and open a new, and write to it.
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", image_count);
                img = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                image_count++;
            }
        }
        // Write 512 bytes until a new JPEG is found
        else
        {
            if (img != NULL)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
        }
    }
    fclose(inptr);
    fclose(img);
    return 0;
}

bool new_image(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}
