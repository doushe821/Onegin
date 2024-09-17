#include <stdlib.h>
#include <string.h>

#include "wqsort.h"

void wqsort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    if(count <= 1)
    {
        return;
    }

    void* base = calloc(1, size);
    memcpy(base, ((char*)ptr) + count - 1, size);
    void* temp = calloc(1, sizeof(ptr)); 

    size_t i = 0;
    size_t j = 0;
    while(i < count)
    {
        while((*comp)((char*)ptr + i, base) == 1 && i < count) 
        {
            i++;
        }
        while(((*comp)((char*)ptr + j, base) == -1 || (*comp)((char*)ptr + j, base) == 0) && j < i)
        {
            j++;
        }

        memcpy(temp, ((char*)ptr + j), size);
        memcpy(((char*)ptr + j), ((char*)ptr + i), size);
        memcpy(((char*)ptr + i), temp, size);

        i++;
    }

    free(temp);
    free(base);

    wqsort(ptr, j, size, comp);
    wqsort(((char*)ptr + j + 1), count - j - 1, size, comp);
}