// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


bool valid(string password);
bool hasUpper(string password, int length);
bool hasLower(string password, int length);
bool hasDigit(string password, int length);
bool hasSymbol(string password, int length);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Checks if provided passwork has minimum 1 uppercase, lowercase, alphanumeric and symbol
bool valid(string password)
{
    int length = strlen(password);
    if(hasUpper(password, length) && hasLower(password, length) && hasDigit(password, length) && hasSymbol(password, length))
    {
        return true;
    }

    else
    {
        return false;
    }
}


// Checks if provided passwork has minimum 1 uppercase
bool hasUpper(string password, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(isupper(password[i]))
        {
            return true;
        }
    }

    return false;
}

// Checks if provided passwork has minimum 1 lowercase
bool hasLower(string password, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(islower(password[i]))
        {
            return true;
        }
    }

    return false;
}


// Checks if provided passwork has minimum 1 alphanumeric
bool hasDigit(string password, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(isdigit(password[i]))
        {
            return true;
        }
    }

    return false;
}


// Checks if provided passwork has minimum 1 symbol
bool hasSymbol(string password, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(ispunct(password[i]))
        {
            return true;
        }
    }

    return false;
}