#include <cs50.h>
#include <stdio.h>

int get_height(void);


int main(void)
{
    int height = get_height();


}

int get_height(void)
{
    do
    {
        int height = get_int("Height: ");
    }
    while(1 <= height <= 8);
    return height
}