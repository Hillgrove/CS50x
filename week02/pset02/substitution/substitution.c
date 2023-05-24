/*
A program that implements a substitution cipher
*/

#include <cs50.h>
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
        printf("Program must have 1 argument to work\n");
        return 1;
    }

    // Get key
    string key = argv[1];

    // Validate key
    if (!is_valid(key))
    {
        printf("not-valid\n");
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
    return false;
}


// TODO: check for non-alphabetic characters
bool only_alpha(string key)
{
    for (int i = 0, int len = strlen(key); i < len; i++)
    {
        if (key[i])
    }
    return true;
}


// TODO: check for repeated characters (case-insensitive)
bool no_repeats(string key)
{
    return false;
}