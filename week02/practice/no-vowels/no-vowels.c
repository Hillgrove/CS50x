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
        string leetspeak = replace(argv[1]);
        printf("%s\n", leetspeak);
    }

    else
    {
        printf("Command incorrect. Please provide a single string to convert.\n");
        return 1;
    }
}


string replace(string word)
{
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        if (argument[i] == 'a')
        {
            argument[i] = '6';
        }

        else if (argument[i] == 'e')
        {
            argument[i] = '3';
        }

        else if (argument[i] == 'i')
        {
            argument[i] = '1';
        }

        else if (argument[i] == 'o')
        {
            argument[i] = '0';
        }
    }

    return word;
}