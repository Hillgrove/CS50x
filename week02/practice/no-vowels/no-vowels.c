// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>


string replace(string argument);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s", replace(argv[1]));
    }

    else
    {
        printf("Command incorrect. Please provide a single string to convert.\n");
        return 1;
    }
}


string replace(string argument)
{
    int length = strlen(argument);

    for (i = 0; i < length; i++)
    {
        if (argument[i] == 'a')
        {
            argument[i] == '6';
        }

        elseif (argument[i] == 'e')
        {
            printf(3);
        }

        elseif (argument[i] == 'i')
        {
            printf(1);
        }

        elseif (argument[i] == 'o')
        {
            printf(0);
        }

        else
        {
            printf(argument[i]);
        }
    }
}