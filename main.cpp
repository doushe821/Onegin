#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "OneginIO.h"

#include "SoftAssert.h"
#include "wqsort.h"

struct Text Onegin = {0, 0, 0, 0};
 
int main()
{  
    readFromFile(&Onegin, "fullOnegin.txt");

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.lines), fstrcmp);
    outputSortedText(&Onegin, "Sorted.txt", "w+b");
    printf("Sorting forward done.\n");

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.lines), &bstrcmp);
    outputSortedText(&Onegin, "SortedBackwards.txt", "w+b");
    printf("Backward sorting is done, enjoy new rhymes!");

    free(Onegin.lines);
    free(Onegin.buffer);
}



