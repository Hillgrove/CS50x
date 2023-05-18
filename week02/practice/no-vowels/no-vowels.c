// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string argument);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s", replace(argv[1]));
    }

    else
    {
        printf("Command incorrect. Please provide a single string to convert\n");
        return 1;
    }
}


string replace(string argument)
{
    return "so far so good\n";
}