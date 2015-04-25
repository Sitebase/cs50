/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    // n must be positive
    if ( n < 0 ) 
        return false;
    
    // search in values
    for (int i = 0; i < n ; i++)
        if ( value == values[ i ] )
            return true;

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int skip = 1;
    for ( int j = 0; j < (n-1) ; j++ )
    {
        for ( int i = 0; i < (n-skip) ; i++) 
        {
            if ( values[i] > values[i+1] ) {
                swap(&values[i], &values[i+1]);
            }
        }
        skip++;
    }

    return;
}

/**
 * Swap two values
 */
void swap(int* a, int* b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
