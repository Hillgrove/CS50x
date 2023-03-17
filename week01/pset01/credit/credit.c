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

void test();

int main(void)
{
    // long cardnumber = get_cardnr();
    long cardnumber = 378282246310005;
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
    // TODO: Check if AMEX
    // TODO: Check if MasterCard
    // TODO: Check if Visa
    }
    return "INVALID";
}


// Calculates and checks if checksum is correct
bool valid_checksum(long cardnumber)
{
    int digit;
    int length = get_length(cardnumber);

    for (int i = 0; i <= length; i+=2)
    {
        digit = cardnumber % 10;
        cardnumber = cardnumber / 10;
        printf("Digit %i: %i\n", i, digit);
    }
    return false;
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


void test()
{
    long card = 378282246310005;
    printf("*** TESTING ***\n");
    int length = 15;
    int digit = 0;

    printf("Card: %li\n", card);
    int test1 = card % 10;
    long test2 = card / 10;
    printf("Card %%: %i\n", test1);
    printf("Card /: %li\n", test2);

}