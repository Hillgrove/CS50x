#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;
int const BLOCK_SIZE = 512;

bool new_image(BYTE buffer);


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

    // Create buffer to hold <something> TODO: find proper name
    BYTE buffer(BLOCK_SIZE);

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // TODO: Look for beginning of JPEG
        if (new_image(buffer))
        {

        }
        // TODO: Open a new JPEG file
        // TODO: Write 512 bytes until a new JPEG is found
    }
    fclose(inptr);
}

bool new_image(BYTE buffer)
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}



