#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
    }

    int cipher = (long) argv[1];

    printf("argc: %i\n", argc);
    printf("argv: %i\n", cipher);
}