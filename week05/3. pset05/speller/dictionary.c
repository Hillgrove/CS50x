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
// const unsigned int N = 26;
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
    // Hash algorithm courtesy of https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function#FNV-1a_hash
    uint32_t hash = 2166136261;
    uint32_t prime = 16777619;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        hash *= prime;
        hash ^= *word;
    }



    /*
    // Hash algorithm courtesy of www.strchr.com/hash_functions
    unsigned int hash = 5381;
    const int M = 33;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        hash = M * hash + word[i];
    }
    */
   return hash % N;
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
        }
        else
        {
            n->next = table[hashkey];
            table[hashkey] = n;
        }
    }

    /*
    node *temp = table[2];
    while (temp != NULL)
    {
        printf("%s\n",temp->word);
        temp = temp->next;
    }
    */

    fclose(dict);
    return true;
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
