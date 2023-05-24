/*
A program that implements a substitution cipher
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


bool is_valid(string key);
bool length_ok(string key);
bool only_alpha(string key);
bool no_repeats(string key);
string encipher(string plaintext, string key);


int main(int argc, string argv[])
{
    // Checks if only 1 argument has been entered
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get key
    string key = argv[1];

    // Validate key
    if (!is_valid(key))
    {
        return 1;
    }

    // If everything is correct, ask for plaintext
    string plaintext = get_string("Plaintext: ");

    // encipher the plaintext
    string ciphertext = encipher(plaintext, key);

    // prints ciphertext
    printf("Ciphertext: %s\n", ciphertext);
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
    if (strlen(key) == 26)  // TODO: Change number back to 26 when testing done
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


// Check for repeated characters (case-insensitive)
bool no_repeats(string key)
{
    int len = strlen(key);

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            // printf("Comparing %c to %c\n", key[i], key[j]);
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Each character in the key must unique.\n");
                return false;
            }
        }
    }
    return true;
}

// TODO: Encipher
string encipher(string plaintext, string key)
{
    // TODO: for each alphabetic character, determine what letter it maps to
    // TODO: preserve case
    // TODO: leave non-alphabetic charaters as-is
    string ciphertext = plaintext;
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            int alfaindex = plaintext[i] - 65;
            ciphertext[i] = key[alfaindex];
        }

        else if (islower(plaintext[i]))
        {
            int alfaindex = plaintext[i] - 97;
            ciphertext[i] = tolower(key[alfaindex]);
        }




        // printf("i: %i  =>  plaintext letter: %c  => alfaindex: %i  => %c\n", i, plaintext[i], alfaindex, key[alfaindex]);


        /*
        if char = upercase
        if char = lowercase
        if char = not alphabetic
        */
    }
    return ciphertext;
}