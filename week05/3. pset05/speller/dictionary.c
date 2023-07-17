// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Variables for FNV-1a 32-bit
#define PRIME_32 16777619
#define OFFSET_32 2166136261

// Size of table: Next prime after load factor of 0,7 achieved (204427)
const unsigned int N = 20;
unsigned int count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int hashkey = hash(word);
    struct node *current = table[hashkey];

    while (current != NULL)
    {
        if (strcasecmp(current->word, word) == 0)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Convert word to lowercase to ensure correct hash values
    int len = strlen(word);
    char lowercase_word[LENGTH + 1] = "";
    for (int i = 0; i < len; i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[len] = '\0';

    // FNV-1a hash algorithm courtesy of https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function#FNV-1a_hash
    uint32_t prime = PRIME_32;
    uint32_t hash = OFFSET_32;

    for (int i = 0; i < len; i++)
    {
        hash ^= (lowercase_word[i]);
        hash *= prime;
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
        count++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            struct node *cursor = table[i];
            table[i] = table[i]->next;
            free(cursor);

        }
    }
    return true;
}