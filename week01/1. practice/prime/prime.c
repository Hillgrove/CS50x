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
            printf("%i\n", i);
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
    {
        int count = 0;
        for (int i = 2; i <= number; i++)
        {
            if (number % i == 0)
            {
                count++;
            }
        }
        if (count == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
