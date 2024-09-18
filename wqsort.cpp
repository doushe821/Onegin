#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "wqsort.h"
#include "SoftAssert.h"

void objSwapper(void* a, void* b, size_t size);

void wqsort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    
    if(count <= 1)
    {
        return;
    }

    size_t i = 0;
    size_t j = 0;

    while(i < count)
    {
        while((*comp)((char*)ptr + i*size, (char*)ptr + (count - 1)*size) == 1 && i < count)
        {
            i++;
        }
        while(((*comp)((char*)ptr + j*size, (char*)ptr + (count - 1)*size) == -1 || (*comp)((char*)ptr + j*size, (char*)ptr + (count - 1)*size) == 0) && j < i)
        {
            j++; 
        }

        objSwapper((char*)ptr + j*size, (char*)ptr + i*size, size);

        i++;
    }

    wqsort((char*)ptr, j, size, comp);
    wqsort(((char*)ptr + (j + 1)*size), count - j - 1, size, comp);
}

void objSwapper(void* a, void* b, size_t size)
{
    uint64_t buf = 0;
    size_t i = 0;
    do
    {
        
        memcpy(&buf, (char*)a + i*sizeof(buf), sizeof(buf));
        memcpy((char*)a + i*sizeof(buf), (char*)b + i*sizeof(buf), sizeof(buf));
        memcpy((char*)b + i*sizeof(buf), &buf, sizeof(buf));
        i++;
                              
    }while(sizeof(buf)*i < size);
}

