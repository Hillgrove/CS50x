#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("    %i\n", i);
        }
    }
}

bool prime(int number)
{
    if (number == 1)
    {
        return false;
    }
    else if (number == 2)
    {
        return true;
    }
    else
    int count = 0;
    {
        // receives 1 number.. check if that number is a prime and return true if it is.
        // if number modulo running integer (higher than 1) equals 0
        for (int i = 2; i = number; i++)
        {
            if number % i == 0;
            {
                count++
            }
        }
        printf("count for number: %i is %i", number, count);

        return false;
    }
}
