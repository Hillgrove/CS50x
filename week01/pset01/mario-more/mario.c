#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_row(int height, int row);

// runs main function
int main(void)
{
    int height = get_height();
    print_row(3, 1);
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

void print_row(int height, int row)
{
    const string BLOCK = "#";
    const string SPACE = " ";
    int num_blank = height - row;

    // Prints spaces before block
    for(int i = 1; i <= num_blank; i++)
    {
        printf("%s", SPACE);
    }

    // Print left blocks
    for(int i = 1; i <= row; i++)
    {
        printf("%s  ", BLOCK);
    }

    for(int i = 1; i <= row; i++)
    {
        printf("%s\n", BLOCK);
    }
}


// TODO: print blocks
// TODO: print space
// TODO: print blocks