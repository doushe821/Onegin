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
    getFileName(argc, argv, fileName);
    struct Text Onegin = {0, 0, 0, 0};

    readFromFile(&Onegin, "Onegin.txt");

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.nLines)*2, structCmpForwards);
    outputSortedText(&Onegin, "Sorted.txt", "w+b");
    printf("\nSorting forward done.\n");

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.lines)*2, structCmpBackwards);
    outputSortedText(&Onegin, "Sorted.txt", "a+b");
    printf("Backward sorting is done, enjoy new rhymes!\n");

    freeOnegin(Onegin.lines);
    fprintf(stderr, "Structure cleared\n");
    return 0;
}


