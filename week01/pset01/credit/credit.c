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
string check_number(long cardnumber);
int get_length(long cardnumber);
bool test_checksum(long cardnumber);

void test();

int main(void)
{
    // long cardnumber = get_cardnr();
    // string result = check_number(cardnumber);
    // printf("%s\n", result);
    test();

}

long get_cardnumber(void)
{
        long cardnumber = get_long("Number: ");
        int length = get_length(cardnumber);
        return cardnumber;
}


string check_number(long cardnumber)
{
    bool is_valid(long cardnumber);
    // TODO: Check checksum
    // TODO: Check if AMEX
    // TODO: Check if MasterCard
    // TODO: Check if Visa
    return "not made yet";
}


bool is_valid(long cardnumber)
{
    return true;
}


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


bool test_checksum(cardnumber)
{
    
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