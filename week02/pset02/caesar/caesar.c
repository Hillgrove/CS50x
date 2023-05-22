#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool check_input(int num_args, string text[]);
bool is_number(string text);


int main(int argc, string argv[])
{
    bool is_valid = check_input(argc, argv);
    if (is_valid)
    {

    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Checks a string to see if it's correct
bool check_input(int num_args, string text[])
{
    if (num_args == 2 && is_number(text[1]))
    {
        return true;
    }
    else
    {
        return false;
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