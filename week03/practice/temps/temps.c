// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here
    // avg_temp: struct of city and temp
    // temps: array of avg_temp

    int index_lowest = 0;

    // Base Case
    // no unsorted elements remain

    // Recursive Case
    // Search the unsorted part of the data to find the smallest value
    // Swap the smallest found value with the first element of the unsorted part

    for (int i = 0; i < NUM_CITIES; i++)
    {
        int index_highest = i;


        for (int j = i + 1; j < NUM_CITIES - (i + 1); j++)
        {
            printf("Comparing %i: (%s: %i) with %i: (%s: %i)\n", i, temps[index_highest].city, temps[index_highest].temp,  j, temps[j].city, temps[j].temp);

            if (temps[j].temp > temps[index_highest].temp)
            {
                index_highest = j;
                printf("\nFound higher temp with %s: %i\n\n", temps[j].city, temps[j].temp);
            }
        }

        if (i != index_highest)
        {
            printf("\nLoop %i: Highest temp found: (%s: %i)\n\n", i, temps[index_highest].city, temps[index_highest].temp);
            avg_temp temporary = temps[index_highest];
            temps[index_highest] = temps[i];
            temps[i] = temporary;
        }
    }

}


