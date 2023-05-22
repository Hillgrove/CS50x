#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_number(string text);
char rotate(char letter, int key);


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
        // Convert argument string to int
        int key = atoi(argv[1]);

        // Ask user for message
        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");
        // Loop each char in message
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            // encrypt if char is a letter
            if (isalpha(plaintext[i]))
            {
                printf("%c", rotate(plaintext[i], key));
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
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


char rotate(char letter, int key)
{
    int shift = 0;
    if (isupper(letter))
    {
        shift = 'A';
    }

    else
    {
        shift = 'a';
    }

    char c = (letter - shift + key) % 26;
    printf("\nletter: '%c'  ==>  ASCII code: %i  ==>  Cipher ASCII code %i  ==>  Cipher letter: %c\n", letter, (int) letter, (int) (letter - shift + key) % 26, c);

    return c;
}