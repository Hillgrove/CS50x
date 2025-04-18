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
#include <math.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void string2ascii(string message, int length, int ascii_codes[]);
void ascii2binary(int ascii_codes[], int length);
void printarray(int array[], int length);


int main(void)
{
    string message = get_string("Message: ");
    int length = strlen(message);
    int ascii_codes[length];
    string2ascii(message, length, ascii_codes); // converts each char in message to its ASCII code and saves it in an array
    ascii2binary(ascii_codes, length); // converts each ASCII code in array to its 8-bit binary code and print it
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

void string2ascii(string message, int length, int ascii_codes[])
{
    for (int i = 0; i < length; i++)
    {
        ascii_codes[i] = (int) message[i];
    }
}


void ascii2binary(int ascii_codes[], int length)
{
    // for each ASCII code in array
    for (int i = 0; i < length; i++)
    {
        int number = ascii_codes[i];
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};


        // for each digit in 8 bit binary - left to right
        for (int j = 0; j < 8; j++)
        {
            // 128, 64, 32, 16, 8, 4, 2, 1
            int bitdivisor = pow(2, BITS_IN_BYTE - (j + 1));
            if (number / bitdivisor >= 1)
            {
                binary[j] = 1;
                number -= bitdivisor;
            }
        }
        printarray(binary, BITS_IN_BYTE);
    }

}


void printarray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        print_bulb(array[i]);
    }
    printf("\n");
}