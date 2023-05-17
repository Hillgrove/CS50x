#include <cs50.h>
#include <stdio.h>
#include <math.h>


int get_length(long cardnumber);
int calculate_checksum(long cardnumber);
int first_two_digits(long cardnumber);
long get_cardnumber(void);
string check_cardnumber(long cardnumber);
bool valid_checksum(long cardnumber);
bool is_amex(int length, int leading_digits);
bool is_mastercard(int length, int leading_digits);
bool is_visa(int length, int leading_digits);


// ask for cardnumber and check if it's valid and belongs to Mastercard, Visa or American Express
int main(void)
{
    long cardnumber = get_cardnumber();
    string result = check_cardnumber(cardnumber);
    printf("%s\n", result);
}


// Ask user for cardnumber
long get_cardnumber(void)
{
        long cardnumber = get_long("Number: ");
        return cardnumber;
}


// Check if number is valid and if so which supplier it belongs to
string check_cardnumber(long cardnumber)
{
    if (valid_checksum(cardnumber))
    {
        int length = get_length(cardnumber);
        int leading_digits = first_two_digits(cardnumber);

        if (is_amex(length, leading_digits))
        {
            return "AMEX";
        }

        if (is_mastercard(length, leading_digits))
        {
            return "MASTERCARD";
        }

        if (is_visa(length, leading_digits))
        {
            return "VISA";
        }

        else
        {
            return "INVALID";
        }
    }
    return "INVALID";
}


/*
Check if checksum is correct by using Luhn's Algorithm

Luhn’s Algorithm
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/
bool valid_checksum(long cardnumber)
{
    int checksum = calculate_checksum(cardnumber);

    if (checksum % 10 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}


// Calculate checksum
int calculate_checksum(long cardnumber)
{
    int digit;
    int checksum = 0;
    int length = get_length(cardnumber);

    // loops through each digit of the cardnumber
    for (int i = 1; i <= length; i++)
    {
        digit = cardnumber % 10;

        // all even numbers
        if (i % 2 == 0)
        {
            int temp_sum = digit * 2;

            // do cross sum if sum higher than or equal to 10
            if (temp_sum >= 10)
            {
                checksum += (temp_sum % 10) + (temp_sum / 10);
            }
            else
            {
                checksum += temp_sum;
            }
        }

        // all uneven numbers
        if (i % 2 != 0)
        {
            checksum += digit;
        }
        cardnumber = cardnumber / 10;
    }
    return checksum;
}


// Return the length of the cardnumber
int get_length(long cardnumber)
{
    int length = 0;
    do
    {
        cardnumber = cardnumber / 10;
        length++;
    }
    while (cardnumber > 0);
    return length;
}

// check if valid American Express
// American Express uses 15-digit numbers
// All American Express numbers start with 34 or 37
bool is_amex(int length, int leading_digits)
{
    if (length == 15)
    {
        if (leading_digits == 34 || leading_digits == 37)
        return true;

        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
}

// check if valid mastercard
// MasterCard uses 16-digit numbers
// most MasterCard numbers start with 51, 52, 53, 54, or 55
bool is_mastercard(int length, int leading_digits)
{

    if (length == 16)
    {
        if (51 <= leading_digits && leading_digits <= 55)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
}

// check if valid VISA
// Visa uses 13- and 16-digit numbers
// all Visa numbers start with 4
bool is_visa(int length, int leading_digits)
{

    if (length == 13 || length == 16)
    {
        if (leading_digits / 10 == 4)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
}


// find first 2 digits of a long int
int first_two_digits(long cardnumber)
{
    int leading_digits = 0;
    int length = get_length(cardnumber);

    leading_digits = cardnumber / pow(10,length - 2);

    return leading_digits;
}