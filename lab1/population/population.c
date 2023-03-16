#include <cs50.h>
#include <stdio.h>

int get_start(void);
int get_end(int start_size);
int num_years (int start, int end);

int main(void)
{
    int start = get_start();
    int end = get_end(start);
    int years = num_years(start, end);
}

// Prompts for start size
int get_start(void)
{
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    return start_size;
}

// Prompts for end size
int get_end(int start_size)
{
    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    }
    while (start_size > end_size);

    return end_size;
}

// Calculate number of years until we reach threshold
int num_years (start, end)
{
    int dead, born;
    int years = 0;
    int population = start;

    while (population < end)
    {
        dead = start / 4;
        born = start / 3;
        population = start + dead - born;
        years++;
    }

    printf("Years: %i", years);
    return years;
}


// TODO: Print number of years