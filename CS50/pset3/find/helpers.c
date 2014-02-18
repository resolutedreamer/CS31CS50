/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
	
	bool foundflag = false;
	
	if (n < 1)
	{
	    return false;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (values[i] == value)
		{
			foundflag = true;
	    }
	}
	
	if (foundflag == true)
	{
	    return true;
	}
	else
	{
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
	/*
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
    */   
	
    return;
}
