#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc != 2 || isalpha(argv[1][0]))
    {
        printf("Usage: ./caesar key\n");
    }

    else
    {
        int cipher = atoi(argv[1]);

        printf("argc: %i\n", argc);
        printf("argv: %i\n", cipher);
    }

    return 0;
}