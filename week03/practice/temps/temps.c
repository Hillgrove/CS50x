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

// Sort cities by temperature in descending order
void sort_cities(void)
{
    // avg_temp: struct of city and temp
    // temps: array of avg_temp

    int index_highest = 0;

    for (int i = 0; i < NUM_CITIES - 1; i++)
    {
        // printf("\n************\n*  Loop %i  *\n************\n", i);

        for (int j = i + 1; j < NUM_CITIES; j++)
        {
            // printf("Comparing index: %i with index: %i\n", index_highest, j);
            if (temps[j].temp > temps[index_highest].temp)
            {
                // printf("\n>>> %s: %i is bigger than %s: %i\n\n", temps[j].city, temps[j].temp, temps[index_highest].city, temps[index_highest].temp);
                index_highest = j;
            }
        }
        // printf("\nFound highest of loop %i\n", i);
        // printf("Swapping index: %i (%s: %i) with index: %i (%s: %i)\n", i, temps[i].city, temps[i].temp, index_highest, temps[index_highest].city, temps[index_highest].temp);

        avg_temp temporary = temps[index_highest];
        temps[index_highest] = temps[i];
        temps[i] = temporary;
    }
}



