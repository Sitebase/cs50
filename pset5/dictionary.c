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
int totalWords = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* current = root;

    for(int i=0; i < LENGTH; i++) {

        char letter = tolower(word[i]);

        // if end of word break loop
        if(letter == '\0')
            break;

        // calculate trie node index for the current letter
        int index = letter - 'a';

        // check if letter is in node
        if(current->children[index] == NULL)
            return false;
        else 
            current = current->children[index];
       
    }

    if(current->is_word)
        return true;

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

    // allocate memory for the root node
    root = calloc(27, sizeof(node));

    // create variable that can be used to temp store the read character
    char character;

    // set the current cursor to point to the root node
    node* current = root;

    // loop character per character over the complete input file
    while((character = fgetc(fp)) != EOF)
    {

        // if new line is detect we now that a word has ended
        // so time to mark the current position in the trie as a complete word
        // and reset the pointer
        if(character == '\n') 
        {

            if(!current->is_word) 
            {
                // mark current as a word
                current->is_word = true;

                // increment word count
                totalWords++;
            }

            // resset cursor
            current = root;

        } 
        
        // insert letter in the trie if needed
        else {
            printf("letter: %c\n", character);

            // calculate the index of the character in the trie (a=0, b=1, ...)
            int index = character - 'a';

            // insert the letter in the trie if not available yet
            if(current->children[index] == NULL)
                current->children[index] = calloc(27, sizeof(node));

            // move the trie cursor to the next node
            current = current->children[index];
        }
    }

    printf("total words: %i\n", totalWords);
    return true;
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
