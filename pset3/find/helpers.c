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

    if( n < 0 )
      return false;

    int i;
    for( i=0 ; i < n ; i++ )
    {
      int compare = values[i];
      // printf("value:%d\n", values[i]);
      if( value == compare )
        return true;
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i, j, swap;
    for(i = 0; i < n; i++) {
      for(j = 0; j < n - i - 1; j++) {
        if(values[j] > values[j+1]) {
          swap = values[j];
          values[j] = values[j+1];
          values[j+1] = swap;
        }
      }
    }
    return;
}
