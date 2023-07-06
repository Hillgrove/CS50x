#include <stdio.h>
#include <stdlib.h>


bool wrong_arguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if (wrong_arguments(argc, argv))
    {
        return 1;
    }
    // TODO: Open memory card
    // TODO: Look for beginning of JPEG
    // TODO: Open a new JPEG file
    // TODO: Write 512 bytes until a new JPEG is found
    // TODO: Stop at end of file
}

bool wrong_arguments(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return true;
    }
    return false;
}