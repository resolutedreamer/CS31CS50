#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"


void vigenere(string key);

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Yell at user");
        return 1;
    }
    string key = argv[1];
    for (int z = 0; z < strlen(key);z++)
    {
        if(!isalpha(key[z]))
        {
            printf("Yell at user even more!");
            return 1;
        }
    }
    vigenere(key);
}

void vigenere(string key)
{
    string texttotransform = GetString();
    string cipheredtext = texttotransform;
    int j = 0;
    //actually perform the transformation
    for (int i = 0; i < strlen(texttotransform); i++)
    {
        // we want to check if it is a letter before we encipher it
        if (isalpha(texttotransform[i]))
        {
            // one branch for uppercase letters
            if (isupper(texttotransform[i]))
            {
                cipheredtext[i] = (texttotransform[i] - 'A' + (tolower(key[j])-'a')) % 26 + 'A';
            }
            
            // one branch for lowercase letters
            else if (islower(texttotransform[i]))
            {
                cipheredtext[i] = (texttotransform[i] - 'a' + (tolower(key[j])-'a')) % 26 + 'a';
            }
            
            // after ciphering, use the next key
            j++;
            
            // check if we need to wrap the key around
            if (j == strlen(key))
            {
                j = 0;
            }
        }
        // if it is not a letter, do nothing
        else
        {
        
        }
    }
    
    printf("%s\n",cipheredtext);
}
