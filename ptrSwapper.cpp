#include <stdlib.h>
#include <string.h>
#include "SoftAssert.h"
#include "OneginIO.h"
void ptrSwap(char** ptr1, char** ptr2, size_t size)
{
    char** temp = (char**)calloc(1, sizeof(ptr1));
    *temp = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = *temp;
    //whisper("\nLines swapped\n");
    free(temp);
}