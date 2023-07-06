#include <stdio.h>
#include <stdlib.h>

typedef unint8_t BYTE;
int const BLOCK_SIZE = 512;



int main(int argc, char *argv[])
{
    // Check if CLI arguments are correct
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Remember filename
    char *infile = argv[1];

    // Open source file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // Create buffer to hold 
    BYTE buffer(BLOCK_SIZE);

    while (fread)


    // TODO: Open memory card
    // TODO: Look for beginning of JPEG
    // TODO: Open a new JPEG file
    // TODO: Write 512 bytes until a new JPEG is found
    // TODO: Stop at end of file
    fclose(inptr);
}