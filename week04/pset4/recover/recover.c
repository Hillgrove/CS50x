#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void wrong_arguments(int argc);

int main(int argc, char *argv[])
{
    // Check if CLI arguments are correct
    wrong_arguments(argc);


    // Remember filename
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }



    // TODO: Open memory card
    // TODO: Look for beginning of JPEG
    // TODO: Open a new JPEG file
    // TODO: Write 512 bytes until a new JPEG is found
    // TODO: Stop at end of file
    fclose(inptr);
}

void wrong_arguments(int argc)
{
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        exit(1);
    }
}