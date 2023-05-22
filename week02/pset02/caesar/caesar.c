#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool check_input(int argc, string argv[]);


int main(int argc, string argv[])
{
    // Checks if argument is correct
    bool isValid = check_input(argc, argv);

    if (isValid())

    return 0;
}


bool valid_input(int argc, string argv[])
{
    if (argc != 2 || isalpha(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
    else
    {
        return true;
    }
}