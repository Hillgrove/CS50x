#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];
bool matrix[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
bool is_loop = false;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool loop(int winner, int loser);
void resetMatrix(void);
void print_winner(void);

// Debug functions
void print_preferences(void);
void print_pairs(void);
void print_locked(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    // print_preferences();  // TODO: REMOVE THESE WHEN PROGRAM DONE
    add_pairs();
    // print_pairs();  // TODO: REMOVE THESE WHEN PROGRAM DONE
    sort_pairs();
    // print_pairs();  // TODO: REMOVE THESE WHEN PROGRAM DONE
    lock_pairs();
    // printf("\nFinal locked matrix\n"); // TODO: REMOVE THESE WHEN PROGRAM DONE
    // print_locked(); // TODO: REMOVE THESE WHEN PROGRAM DONE
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // If candidate is valid, update ranks array with the index of the candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // preferences[a][b] is number of voters who prefer a over b
    for (int i = 0; i < candidate_count; i++)
    {
        // index of candidate A
        int a = ranks[i];

        for (int j = i + 1; j < candidate_count; j++)
        {
            // index of candidate B
            int b = ranks[j];

            preferences[a][b] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count += 1;
            }

            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count += 1;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength (margin) of victory
void sort_pairs(void)
{
    int max_idx;

    for (int i = 0; i < pair_count - 1; i++)
    {
        max_idx = i;

        for (int j = i + 1; j < pair_count; j++)
        {
            // save the difference between the amount of voters of winner and looser of the 2 pairs we're comparing
            int marginOne = preferences[pairs[max_idx].winner][pairs[max_idx].loser] - preferences[pairs[max_idx].loser][pairs[max_idx].winner];
            int marginTwo = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];

            if (marginTwo > marginOne)
            {
                max_idx = j;
            }
        }

        // Swap the found maximum element with the first element
        if (max_idx != i)
        {
            pair temp = pairs[max_idx];
            pairs[max_idx] = pairs[i];
            pairs[i] = temp;
        }
    }
    return;
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // Sets grid to locked to test it
        locked[pairs[i].winner][pairs[i].loser] = true;

        // check if edges form a cycle
        is_loop = false;
        if (loop(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
        resetMatrix();
        // printf("\nTemp locked matrix after checking (%i, %i):\n", pairs[i].winner, pairs[i].loser);
        // print_locked();
    }
    return;
}


bool loop(int winner, int loser)
{
    matrix[winner][loser] = true;
    int i = loser;

    for (int j = 0; j < candidate_count; j++)
    {
        if (locked[i][j] == true)
        {
            if (matrix[i][j] == true && is_loop == false)
            {
                // resetMatrix();
                is_loop = true;
                break;
            }
            loop(i, j);
        }
    }
    return is_loop;
}


void resetMatrix(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            matrix[i][j] = false;
        }
    }
}


// Print the winner of the election
void print_winner(void)
{
    for (int j = 0; j < candidate_count; j++)
    {
        int sum = 0;

        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][j] == 1)
            {
                sum += 1;
            }
        }
        if (sum == 0)
        {
            printf("%s\n", candidates[j]);
        }
    }
    return;
}

void print_preferences(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i   ", preferences[i][j]);
        }
        printf("\n");
    }
    return;
}


void print_pairs(void)
{
    printf("\npairs array:\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("(%i, %i) ", pairs[i].winner, pairs[i].loser);
    }
    printf("\n");
    return;
}


void print_locked(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i   ", locked[i][j]);
        }
        printf("\n");
    }
    return;
}