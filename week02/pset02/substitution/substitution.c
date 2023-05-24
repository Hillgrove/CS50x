/*
A program that implements a substitution cipher
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>


bool not_valid(string key);
bool wrong_length(string key);
bool not_alpha(string key);
bool repeated_chars(string key);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // TODO: Find suitable error message
        printf("error message of your choice\n");
        return 1;
    }

    // Get key
    string key = argv[1];

    // Validate key
    if (not_valid(key))
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
bool not_valid(string key)
{
    if (wrong_length(key) || not_alpha(key) || repeated_chars(key))
    {
        return false;
    }
    return true;
}

// Check key length
bool wrong_length(string key)
{
    if (strlen(key) == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// TODO: check for non-alphabetic characters
bool not_alpha(string key)
{
    return true;
}


// TODO: check for repeated characters (case-insensitive)
bool repeated_chars(string key)
{
    return true;
}