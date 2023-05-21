/*
Let’s write a program called bulbs that takes a message and converts it to a set of bulbs that we could show to an unsuspecting audience. We’ll do it in two steps:

The first step consists of turning the text into decimal numbers. Let’s say we want to encode the message HI!. Luckily, we already have a convention in place for how to do this, ASCII.
Notice that H is represented by the decimal number 72, I is represented by 73, and ! is represented by 33.

The next step involves taking our decimal numbers (like 72, 73, and 33) and converting them into equivalent binary numbers, which only use 0s and 1s. For the sake of having a consistent
number of bits in each of our binary numbers, assume that each decimal is represented with 8 bits. 72 is 01001000, 73 is 01001001, and 33 is 00100001.

Lastly, we’ll interpret these binary numbers as instructions for the light bulbs on stage; 0 is off, 1 is on. (You’ll find that bulbs.c includes a print_bulb function that’s been implemented
for you, which takes in a 0 or 1 and outputs emoji representing light bulbs.)
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int string2ascii(string message);

int main(void)
{
    string message = get_string("Message: ");
    int length = strlen(message);
    int ascii_codes[length] = string2ascii(message);


    // TODO: convert the given string into a series of 8-bit binary numbers, one for each character of the string.
    // TODO: use the provided print_bulb function to print a series of 0s and 1s as a series of yellow and black emoji, which represent on and off light bulbs.
    // TODO: Each “byte” of 8 symbols should be printed on its own line when outputted; there should be a \n after the last “byte” of 8 symbols as well.
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

int string2ascii(string message)
{
    int length = strlen(message);
    int ascii_codes[length];

    for (int i = 0; i < length; i++)
    {
        ascii_codes[i] = (int) message[i];
    }

    return ascii_codes[];
}