#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "SoftAssert.h"
#include "OneginIO.h"

int structCmpForwards(const void* a, const void* b)
{
    aIndex = 0;
    bIndex = 0;
    while(*(*((char**)a) + aIndex) != '\0' && *(*((char**)b) + bIndex) != '\0')
    {
        if(isalpha(*(*((char**)a) + aIndex)) || *(*((char**)a) + aIndex) == '\0')
        {

            if(isalpha(*(*((char**)b) + bIndex)) || *(*((char**)b) + bIndex) == '\0')
            {
                if(tolower(*(*((char**)a) + aIndex)) - tolower(*(*((char**)b) + bIndex)) > 0)
                {
                    return 1;
                }

                else if(tolower(*(*((char**)a) + aIndex)) - tolower(*(*((char**)b) + bIndex)) < 0)
                {
                    return -1; 
                }

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
    }
    return 0;
}

int structCmpBackwards(const void* a, const void* b)
{

}