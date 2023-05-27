#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

// Recursively convert each litteral char to litteral int
int convert(string input)
{
    int length = strlen(input);
    int i = input[length - 1] - '0';

    // Base case
    if (length == 1)
    {
        return i;
    }

    else
    {
        input[length - 1] = '\0';
        return i + 10 * convert(input);
    }
}