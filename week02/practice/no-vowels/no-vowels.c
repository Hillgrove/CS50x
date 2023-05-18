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
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;

            default:
                break;
        }
    }

    return word;
}