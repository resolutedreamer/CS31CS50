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
    // TODO: implement a searching algorithm
    int i;
	for (i = 0; i < n; i++)
	{
	    printf("something\n");
	    printf("i = %d\n", i);
		printf("values[i] = %d\n", values[i]);
	    if (values[i] == value)
		{
			return true;
		}
	}
	printf("values[0] = %d\n", values[0]);
	printf("values[1] = %d\n", values[1]);
	printf("values[2] = %d\n", values[2]);
	printf("values[84] = %d\n", values[84]);
	
    return false;
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
        //printf("%dth iteration\n %d is smallest\n",i, smallestnumber);
        int temp1 = values[i];
        int temp2 = smallestnumber;
        values[i] = temp2;
        values[smallestnumberindex] = temp1;
        k = 0;
        smallestnumber = 50;
    }
    
	
    return;
}
