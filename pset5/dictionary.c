/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// remove after debugging is done
#include <stdio.h>

node* root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    printf("dic is: %s", dictionary);

    // open dictonary file to read
    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL){
        printf("Could not open file %s\n", dictionary);
        return false;
    }

    // create variable that can be used to temp store the read character
    char character;
    char word[LENGTH];

    // loop over dictionary file
    do {
        character = fscanf(fp, "%s", word);
        printf("word: %s\n", word);

        // insert word in trie
        


    } while(character != EOF);
    
    return false;
}

bool insertWord(char* word)
{
    return true;
}

/**
 * calculation character index 
 */
int getIndex(char c)
{
    return tolower(c) - 'a';
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
