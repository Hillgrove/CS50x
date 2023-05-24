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
        printf("error message of your choice\n");
        return 1;
    }

    // Get key
    string key = argv[1];

    // Validate key
    if (is_valid(key))
    {
        printf("valid\n");
    }
    else
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
    else
    {
        return false;
    }
}

// Check key length
bool length_ok(string key)
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
bool only_alpha(string key)
{
    return true;
}


// TODO: check for repeated characters (case-insensitive)
bool no_repeats(string key)
{
    return true;
}