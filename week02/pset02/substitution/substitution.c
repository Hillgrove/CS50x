/*
A program that implements a substitution cipher


Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.


*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


bool is_valid(string key);
bool length_ok(string key);
bool only_alpha(string key);
bool no_repeats(string key);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // TODO: Find suitable error message
        printf("Program must have one and only one argument.\n");
        return 1;
    }

    // Get key
    string key = argv[1];

    // Validate key
    if (!is_valid(key))
    {
        printf("key not valid\n");
        return 1;
    }



    // TODO: Get plaintext
    // TODO: Encipher
        // TODO: for each alphabetic character, determine what letter it maps to
        // TODO: preserve case
        // TODO: leave non-alphabetic charaters as-is
    // TODO: Print ciphertext


}


// Validate key
bool is_valid(string key)
{
    if (length_ok(key) && only_alpha(key) && no_repeats(key))
    {
        return true;
    }
    return false;
}

// Check key length
bool length_ok(string key)
{
    if (strlen(key) == 26)
    {
        return true;
    }
    printf("Key must contain 26 characters.\n");
    return false;
}


// Check for non-alphabetic characters
bool only_alpha(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetic only.\n");
            return false;
        }
    }
    return true;
}


// TODO: check for repeated characters (case-insensitive)
bool no_repeats(string key)
{
    int len = strlen(key);

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            printf("Comparing %c to %c\n", key[i], key[j]);
            if (key[i] == key[j])
            {
                printf("key is the same\n");
                return false;
            }
        }
    }
    return true;
}