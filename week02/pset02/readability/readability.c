/*
For this problem, you’ll implement a program that calculates the approximate grade level needed to comprehend some text, per the below.

The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

index = 0.0588 * L - 0.296 * S - 15.8

where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);


int main(void)
{
    string text = get_string("Text: ");

    int letters = letter_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);

    printf("Letter count: %i\n", letters);
    printf("Word count: %i\n", words);
    printf("Sentence count: %i\n", sentences);

    // TODO: calculate average number of letters er 100 words
    // TODO: calculate average number of sentences pr 100 words
    // TODO: calculate coleman-Liau score
    // TODO: print result
}

// counts the number of letters in the text
// You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z
int letter_count(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

// counts the number of words in the text
// any sequence of characters separated by spaces should count as a word
int word_count(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            count++;
        }
    }

    return count;
}


// TODO: Complete function
int sentence_count(string text)
{
    int sum = 0;
    return 0;
}