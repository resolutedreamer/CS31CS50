#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"


void caesar(int key);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Yell at user");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        
        caesar(key);
    }
}

void caesar(int key)
{
    string texttotransform = GetString();
    string cipheredtext = texttotransform;
    
    //actually perform the transformation
    for (int i = 0; i < strlen(texttotransform); i++)
    {
        if (isspace(texttotransform[i]))
        {
                
        }
        else if (isupper(texttotransform[i]))
        {
            cipheredtext[i] = (texttotransform[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower(texttotransform[i]))
        {
            cipheredtext[i] = (texttotransform[i] - 'a' + key) % 26 + 'a';
        }
    }
    
    printf("%s\n",cipheredtext);
}
