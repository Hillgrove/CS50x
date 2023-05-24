/*
A program that implements a substitution cipher
*/

#include <cs50.h>
#include <stdio.h>


bool is_valid(string key);


int main(int argc, string argv[])
{
    // Get key
    string key = argv[1];

    // Validate key
    if (is_valid(key))
    {

    }


    // TODO: Get plaintext
    // TODO: Encipher
        // TODO: for each alphabetic character, determine what letter it maps to
        // TODO: preserve case
        // TODO: leave non-alphabetic charaters as-is
    // TODO: Print ciphertext


}


// Validate key
bool is_valid()
{

    if (length_ok() && only_alpha() && no_repeats())
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



// TODO: check for non-alphabetic characters
// TODO: check for repeated characters (case-insensitive)

