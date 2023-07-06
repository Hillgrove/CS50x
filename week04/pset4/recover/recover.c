#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int wrong_arguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    wrong_arguments(argc, argv);
    // TODO: Open memory card
    // TODO: Look for beginning of JPEG
    // TODO: Open a new JPEG file
    // TODO: Write 512 bytes until a new JPEG is found
    // TODO: Stop at end of file
}

int wrong_arguments(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }
    return 0;
}