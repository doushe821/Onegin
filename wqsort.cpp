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
    // ?
    void* base = calloc(1, size);
    memcpy(base, (char*)ptr + (count - 1)*size, size);

    void* temp = calloc(1, size); 

    size_t i = 0;
    size_t j = 0;

    while(i < count)
    {
        while((*comp)((char*)ptr + i*size, base) == 1 && i < count)
        {
            //whisper("i++");
            i++;
        }
        //fprintf(stderr, "%zu", i);
        while(((*comp)((char*)ptr + j*size, base) == -1 || (*comp)((char*)ptr + j*size, base) == 0) && j < i)
        {
            //whisper("j++");
            j++; 
        }
        //fprintf(stderr, "i, j: %zu, %zu\n", i, j);
        //fprintf(stderr, "A: %s\nB: %s\n", *((char**)ptr + j*size), *((char**)ptr + i*size));
        // int64_t
        memcpy(temp, (char*)ptr + j*size, size);
        memcpy((char*)ptr + j*size, (char*)ptr + i*size, size);
        memcpy((char*)ptr + i*size, temp, size);
        //fprintf(stderr, "A1: %s\nB2: %s\n", *((char**)ptr + j*size), *((char**)ptr + i*size));
        //whisper("Swpa done\n");
        i++;
        //fprintf(stderr, "%zu, %zu \n", i, i*size);
    }
    //whisper("cringe but free\n");
    free(temp);
    free(base);

    wqsort((char*)ptr, j, size, comp);
    wqsort(((char*)ptr + (j + 1)*size), count - j - 1, size, comp);
}

void objSwapper()
{
    
}