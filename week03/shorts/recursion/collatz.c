#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = get_int("Please select an integer: ");
    int steps = collatz(n);
    printf("function took %i steps.\n", steps);
}


int collatz(int n)
{
    if (n == 1)
        return 0;

    else if (n % 2 == 0)
        return 1 + collatz(n/2);

    else
        return 1 + collatz(3 * n + 1);
}
