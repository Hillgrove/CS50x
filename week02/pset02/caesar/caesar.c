#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2 && isalpha(argv[0]))
    {
        printf("Usage: ./caesar key");
    }

    printf("argc: %i\n", argc);
    printf("argv: %s\n", argv[0]);
}