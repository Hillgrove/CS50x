#include <stdio.h>
#include <stdlib.h>


bool argument_ok(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if (argument_ok(argc, argv))
    {
        return 1;
    }
    // TODO: Open memory card
    // TODO: Look for beginning of JPEG
    // TODO: Open a new JPEG file
    // TODO: Write 512 bytes until a new JPEG is found
    // TODO: Stop at end of file
}

bool argument_ok(int argc, char *argv[])
{

}