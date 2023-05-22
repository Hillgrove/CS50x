#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool check_input(int number, string text[]);


int main(int argc, string argv[])
{
    // Checks if argument is correct
    bool is_Valid = check_input(argc, argv);

    if (is_Valid())

    return 0;
}

// Checks a string to see if it's correct
bool valid_input(int number, string text[])
{
    if (number != 2 || isalpha(text[1]))
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
    else
    {
        return true;
    }
}

// Checks if a string is only numbers
bool is_number(int length, string text)
{

}