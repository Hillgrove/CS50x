#include <cs50.h>
#include <stdio.h>

int get_height(void);

// runs main function
int main(void)
{
    int height = get_height();


}

// Prompts for pyramid height
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(1 > height || height > 8);
    return height;
}


// TODO: print spaces before block
// TODO: print blocks
// TODO: print space
// TODO: print blocks
