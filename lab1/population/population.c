#include <cs50.h>
#include <stdio.h>

int get_start(void);
int get_end(int start_size);
int num_years (int start, int end);

int main(void)
{



        // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}

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

int num_years (start, end)
{
    return 0;
}