#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "wqsort.h"
#include "SoftAssert.h"

static void objSwapper(void* a, void* b, size_t size);
static void swap(void* a, void* b, size_t buf);

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

static void objSwapper(void* a, void* b, size_t size)
{
    uint64_t buf8 = 0;
    uint32_t buf4 = 0;
    uint16_t buf2 = 0;
    uint8_t buf1 = 0;
    size_t i = 0;

    while(size - i >= sizeof(buf8))
    {
        swap((char*)a + i, (char*)b + i, buf8);
        i += sizeof(buf8);
    }

    while(size - i >= sizeof(buf4))
    {
        swap((char*)a + i, (char*)b + i, buf4);
        i += sizeof(buf4);                      
    }

    while(size - i >= sizeof(buf2))
    {
        swap((char*)a + i, (char*)b + i, buf2);
        i += sizeof(buf2);   
    }

    while(size - i >= sizeof(buf1))
    {
        swap((char*)a + i, (char*)b + i, buf1);
    }
}

static void swap(void* a, void* b, size_t buf)
{
    memcpy(&buf, (char*)a, sizeof(buf));
    memcpy((char*)a, (char*)b, sizeof(buf));
    memcpy((char*)b, &buf, sizeof(buf));
}
