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

long get_cardnr(void);

int main(void)
{
    long cardnr = get_cardnr();
}

long get_cardnr(void)
{
    do
    {
        cardnr = get_long("Number: ");
        return cardnr;
    }
    while (cardnr > 0)
}