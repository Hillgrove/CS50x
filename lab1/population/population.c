#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start(void)
    {
        int start_size;
        do
        {
            start_size = get_int("Start size: ");
        }
        while (start_size < 9);
    }

    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    }
    while (start_size > end_size);

    int num_years (start, end)


        // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}
