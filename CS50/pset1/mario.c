#include <stdio.h>
#include <cs50.h>

int main()
{
    int height;
    printf("Height: ");
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while(height < 0 || height > 23);
    
    for (int i = height; i > 0; i--)
    {
        int tempj = 0;
        for (int j = (i-1); j > 0 ; j--)
        {
            printf(" ");
            tempj++;
        }
        for (int k = 0; k < ((height + 1) - tempj); k++)
        {
            printf("#");
        }
        printf("\n");
    }
    //printf("%d\n", height);
}
