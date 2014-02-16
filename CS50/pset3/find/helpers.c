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

bool newsearch(int value, int values[], int n)
{
    // my first recursive algorithm...
    if (values[0] == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    // This is a linear searching algorithm
    for (int i = 0; i < n ; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    return false;
    // This is a binary searching algorithm
    //newsearch(value, values, n);
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    for (int i = 0; i < n; i++)
    {
        int smallestnumber = 50, smallestnumberindex = 0;
        int k = i;
        while (k < n)
        {
            if (values[k] < smallestnumber)
            {
                smallestnumber = values[k];
                smallestnumberindex = k;
            }
            k++;
        }
        printf("%dth iteration\n %d is smallest\n",i, smallestnumber);
        int temp1 = values[i];
        int temp2 = smallestnumber;
        values[i] = temp2;
        values[smallestnumberindex] = temp1;
        k = 0;
        smallestnumber = 50;
    }
    
    return;
}
