// Author: Jesus Carlos Martinez Gonzalez
// Date: 11/04/2023
// Speller

// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

unsigned int ctr;
unsigned int key;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    key = hash(word);
    node *curr = table[key];

    // Iterate over the dictionary, comparing each element to 'word'
    while (curr != 0)
    {
        if (strcasecmp(word, curr->word) == 0)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Averages ASCII value of each letter in 'word'
unsigned int hash(const char *word)
{
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // Scan the file for words
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Word
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        // Add word to dictionary
        strcpy(n->word, word);
        key = hash(word);
        n->next = table[key];
        table[key] = n;
        ctr++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (ctr > 0)
    {
        return ctr;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over every element on the dictionary
    for (int i = 0; i < N; i++)
    {
        node *curr = table[i];
        while (curr != NULL)
        {
            // Free each node
            node *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    return true;
}
