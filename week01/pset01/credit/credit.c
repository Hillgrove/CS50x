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
string check_number(long cardnumber);
void test();
int get_length(cardnumber);

int main(void)
{
    // long cardnumber = get_cardnr();
    // string result = check_number(cardnumber);
    // printf("%s\n", result);
    test();

}

long get_cardnr(void)
{
        long cardnr = get_long("Number: ");
        int length = get_length(cardnumber);
        return cardnr;
}

string check_number(long cardnumber)
{
    bool is_valid(long cardnumber);
    // TODO: Check if valid
    // TODO: Check if AMEX
    // TODO: Check if MasterCard
    // TODO: Check if Visa
    return "not made yet";
}

bool is_valid(long cardnumber)
{
    return true;
}

int get_length(cardnumber)
{
    
}

void test()
{
    printf("TESTING\n");
    long number = 378282246310005;
    int length = 0;
    do
    {
        printf("Number before integer div: %lu\n", number);
        number = number / 10;
        printf("Number after integer div: %lu\n", number);
        length++;
        printf("Length of number: %i\n", length);
    }
    while (number > 0);
    printf("Final length of number: %i\n", length);
}