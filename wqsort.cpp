#include <stdlib.h>
#include <string.h>

#include "wqsort.h"
#include "SoftAssert.h"

void wqsort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*))
{
    
    if(count <= 1)
    {
        return;
    }

    void* temp = calloc(1, size); 

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

        memcpy(temp, (char*)ptr + j*size, size);
        memcpy((char*)ptr + j*size, (char*)ptr + i*size, size);
        memcpy((char*)ptr + i*size, temp, size);

        i++;
    }
    free(temp);

    wqsort((char*)ptr, j, size, comp);
    wqsort(((char*)ptr + (j + 1)*size), count - j - 1, size, comp);
}

/*void objSwapper(void* a, void* b, size_t size)
{
    int64_t buf = 0;
    size_t i = 0;
    do
    {
        memcpy(buf, (char*)a, //);
        memcpy((char*)a, (char*)b, //);
        memcpy((char*)b, buf, //);

    }while(buf*i < size);
}*/

