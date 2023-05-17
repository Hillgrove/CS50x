#include <cs50.h>
#include <stdio.h>

/*
American Express uses 15-digit numbers
All American Express numbers start with 34 or 37
MasterCard uses 16-digit numbers
most MasterCard numbers start with 51, 52, 53, 54, or 55
Visa uses 13- and 16-digit numbers
all Visa numbers start with 4

Luhn’s Algorithm
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/

long get_cardnumber(void);
string check_cardnumber(long cardnumber);
int get_length(long cardnumber);
bool valid_checksum(long cardnumber);
int calculate_checksum(long cardnumber);


int main(void)
{
    // long cardnumber = get_cardnr();
    long cardnumber = 378282246310006;
    string result = check_cardnumber(cardnumber);
    printf("%s\n", result);
    // test();
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
        return "VALID";
        // TODO: Check if AMEX
        // TODO: Check if MasterCard
        // TODO: Check if Visa
    }

    else
    {
        return "INVALID";
    }
}


// Checks if checksum is correct
bool valid_checksum(long cardnumber)
{
    int checksum = calculate_checksum(cardnumber);
    printf("checksum mod 10 = %i\n", checksum % 10);

    if (checksum / 10 == 0)
    {
        return false;
    }

    else
    {
        return true;
    }
}



// Calculates checksum
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
    printf("Checksum is: %i\n", checksum);
    return checksum;
}


// Returns the length of the cardnumber
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