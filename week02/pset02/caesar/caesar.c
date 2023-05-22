#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_number(string text);


int main(int argc, string argv[])
{
    // Throw error if more than 1 argument was used
    if (argc != 2)
    {
        printf("Command needs a single numerical argument\n");
        return 1;
    }

    // Check if argument is a number
    else if (!is_number(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // TODO: Convert argument string to int
        // TODO: Ask user for message
        // TODO: Loop each char in message
            // TODO: If letter encode char
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