// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // Read strings from file one at a time
    char word[LENGTH];
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy word from file into node
        strcpy(n->word, word);

        // Hash word to obtain a hash value
        unsigned int hashkey = hash(word);

        // Insert node into hash table at that location
        if (table[hashkey] == NULL)
        {
            table[hashkey]= n;
            table[hashkey]->next = NULL;
        }
        else
        {
            n->next = table[hashkey];
            table[hashkey]->next = n;
        }


        // free(n); // Needed if unload does it?
    }

    node *temp = table[2]; // start at the head of the list at the specific index
    while (temp->next != NULL) // while we haven't reached the end of the list
    {
    printf("%s\n", temp->word); // print the 'word' field of the current node
    temp = temp->next; // move on to the next node
    }


    fclose(dict); // Needed if unload does it?
    return false; // Change to true when function correct
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
