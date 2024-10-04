#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>

#include "OneginIO.h"
#include "SoftAssert.h"
#include "wqsort.h"

int main(int argc, char* argv[])
{  
    char fileName[FILENAME_MAX] = {};
    getFileName(argc, argv, fileName) != 0;

    struct Text Onegin = {0, 0, 0, 0};
    if(readFromFile(&Onegin, "Onegin.txt") != 0)
    {
        return Onegin.err;
    }

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.nLines)*2, structCmpForwards);
    if(outputSortedText(&Onegin, "Sorted.txt", "w+b") != 0)
    {
        return Onegin.err;
    }
    printf("\nSorting forward done.\n");

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.lines)*2, structCmpBackwards);
    if(outputSortedText(&Onegin, "Sorted.txt", "a+b") != 0)
    {
        return Onegin.err;
    }
    printf("Backward sorting is done, enjoy new rhymes!\n");

    freeOnegin(Onegin.lines);
    fprintf(stderr, "Structure cleared\n");
    return 0;
}


