// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// Returns the max value
int max(int array[], int n)
{
    int max;

    for (int i = 0; i < n; i++)
    {
        // Initializes max to array[0] so it's possible to make comparisons
        if (i == 0)
        {
            max = array[0];
        }

        // sets max to new number if higher number is found
        else if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}
