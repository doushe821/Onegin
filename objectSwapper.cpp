#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "wqsort.h"

void swapObjects(void* a, void* b, size_t size)
{
    uint64_t buf8 = 0;
    uint32_t buf4 = 0;
    uint16_t buf2 = 0;
    uint8_t buf1 = 0;

    size_t i = 0;
    //fprintf(stderr, "%zu\n", size);
    //fprintf(stderr, "%zu\n", sizeof(buf8));
    while(size - i > 0)
    {
        /*if(size - i >= sizeof(buf8))
        {*/
            memcpy(&buf8, (char*)a + i, sizeof(buf8));
            memcpy((char*)a + i, (char*)b + i, sizeof(buf8));
            memcpy((char*)b + i, &buf8, sizeof(buf8));
            i += sizeof(buf8); 
            //fprintf(stderr, "%s\n", *((char**)a));
           //fprintf(stderr, "%zu\n", size - i);
        //}
        /*else if(size - i >= sizeof(buf4))
        {
            memcpy(&buf4, (char*)a, sizeof(buf4));
            memcpy((char*)a, (char*)b, sizeof(buf4));
            memcpy((char*)b, &buf4, sizeof(buf4)); 
            i += sizeof(buf4); 
        }
        else if(size - i >= sizeof(buf2))
        {
            memcpy(&buf2, (char*)a, sizeof(buf2));
            memcpy((char*)a, (char*)b, sizeof(buf2));
            memcpy((char*)b, &buf2, sizeof(buf2)); 
            i += sizeof(buf2); 
        }
        else if(size - i >= sizeof(buf1))
        {
            memcpy(&buf1, (char*)a, sizeof(buf1));
            memcpy((char*)a, (char*)b, sizeof(buf1));
            memcpy((char*)b, &buf1, sizeof(buf1)); 
            i += sizeof(buf1);
        }*/
    }
}
