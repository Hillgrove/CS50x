#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_row(int height, int row);
void print_pyramid(int height);

// runs main function
int main(void)
{
    int height = get_height();
    print_pyramid(height);
}

// Prompts for pyramid height
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (1 > height || height > 8);
    return height;
}

// Prints a single row
void print_row(int height, int row)
{
    const string BLOCK = "#";
    const string SPACE = " ";
    int num_blank = height - row;

    // Prints spaces before block
    for (int i = 1; i <= num_blank; i++)
    {
        printf("%s", SPACE);
    }

    // Prints blocks to the left
    for (int i = 1; i <= row; i++)
    {
        printf("%s", BLOCK);
    }

    // Prints space between blocks
    printf("  ");

    // Prints blocks to the left
    for (int i = 1; i <= row; i++)
    {
        printf("%s", BLOCK);
    }
    printf("\n");
}

// Prints the whole pyramid
void print_pyramid(int height)
{
    for (int row = 1; row <= height; row++)
    {
        print_row(height, row);
    }
}