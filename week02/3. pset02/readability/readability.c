/*
For this problem, you’ll implement a program that calculates the approximate grade level needed to comprehend some text, per the below.

The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

index = 0.0588 * L - 0.296 * S - 15.8

where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
*/

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);
float calc_score(int letters, int words, int sentences);


int main(void)
{
    string text = get_string("Text: ");

    int letters = letter_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);
    int score = round(calc_score(letters, words, sentences));


    if (score < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (score >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", score);
    }


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
        // checks if current char is blank
        if (isblank(text[i]))
        {
            count++;
        }
    }
    return count + 1; // As there's no space after the last word, we have to add 1 extra word for the count to be right
}


// counts the number of sentences in the text
// any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
int sentence_count(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // checks if current char is a
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}


// calculate coleman-Liau score
// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
float calc_score(int letters, int words, int sentences)
{
    float L = (float) letters / (float) words * 100; // average number of letters per 100 words
    float S = (float) sentences / (float) words * 100; // average number of sentences per 100 words
    float score = 0.0588 * L - 0.296 * S - 15.8;

    return score;
}