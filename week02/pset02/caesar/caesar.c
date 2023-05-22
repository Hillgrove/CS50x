#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool check_input(int length, string text[]);
bool is_number(int length, string text);


int main(int argc, string argv[])
{
    // Checks if argument is correct
    bool is_valid = check_input(argc, argv);

    return 0;
}

// Checks a string to see if it's correct
bool check_input(int length, string text[])
{
    if (length == 2 && is_number(length, text[1]))
    {
        return true;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
}

// Checks if a string is only numbers
bool is_number(int length, string text)
{
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