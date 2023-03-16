#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size;
    do
    {
        llama = get_int("Input number of llamas: ");
    }
    while (llama < 9);



    printf("Number of llamas: %i\n", llama);



    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}
