#include <stdio.h>
#include "helpers.h"

int main(void)
{
    int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(array, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n",array[i]);
}

