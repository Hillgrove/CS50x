/*
For this problem, you’ll implement a program that calculates the approximate grade level needed to comprehend some text, per the below.

The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

index = 0.0588 * L - 0.296 * S - 15.8

where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>


int number_of_letters(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = number_of_letters(text);
    printf("Number of letters: %i", letters);

    // TODO: calculate average number of letters er 100 words
    // TODO: calculate average number of sentences pr 100 words
    // TODO: calculate coleman-Liau score
    // TODO: print result
}

int number_of_letters(string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        int sum = 0;
        if (isalpha(text[i]))
        {
            sum++
        }
        return sum;
    }
}