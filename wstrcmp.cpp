#include "OneginIO.h"
#include <ctype.h>
#include "SoftAssert.h"
#include <stdio.h>

int fstrcmp(void* a, void* b)
{
    int i = 0;
    fprintf(stderr, "a: %s\nb: %s\n", (char*)a, (char*)b);
    int aIndex = 0;
    int bIndex = 0;
    while(*((char*)a + aIndex) != '\0' && *((char*)b + bIndex) != '\0')
    {
        if(isalpha(*((char*)a + aIndex)) || *((char*)a + aIndex) == '\0')
        {
            if(isalpha(*((char*)b + bIndex)) || *((char*)b + bIndex) == '\0')
            {
                if(tolower(*((char*)a + aIndex)) - tolower(*((char*)b + bIndex)) > 0)
                    return 1;
                else if(tolower(*((char*)a + aIndex)) - tolower(*((char*)b + bIndex)) < 0)
                    return -1;
                else
                {
                    bIndex++;
                    aIndex++;
                } 
            }
            else
                bIndex++;
        }
        else 
            aIndex++;
        //fprintf(stderr, "hehehehe\n");
    }


    return 0;
}

int bstrcmp(void* a, void* b)
{

    
}