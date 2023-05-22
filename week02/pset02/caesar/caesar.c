#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool check_input(int num_args, string text[]);
bool is_number(string text);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Command needs a single numerical argument\n");
        return 1;
    }

    else if (!is_number(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

    }
}


// Checks if a string is only numbers
bool is_number(string text)
{
    int length = strlen(text);
    bool valid = true;

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(text[i]))
        {
            valid = false;
        }
    }
    return valid;
}