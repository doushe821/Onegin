#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "OneginIO.h"

#include "SoftAssert.h"
#include "wqsort.h"

static int getFileName(int c, char** v, char* fName);
 
int main(int argc, char* argv[])
{  
    char fileName[FILENAME_MAX] = {};
    getFileName(argc, argv, fileName);

    fprintf(stderr, "%s\n", fileName);
    struct Text Onegin = {0, 0, 0, 0};
    readFromFile(&Onegin, "Onegin.txt");

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.lines), strcmpForwards);
    outputSortedText(&Onegin, "Sorted.txt", "w+b");
    printf("\nSorting forward done.\n");

    wqsort(Onegin.lines, Onegin.nLines, sizeof(Onegin.lines), strcmpBackwards);
    outputSortedText(&Onegin, "Sorted.txt", "a+b");
    printf("\nBackward sorting is done, enjoy new rhymes!\n");

    freeDynamicMem(&Onegin);
}


static int getFileName(int c, char** v, char* fName)
{
    char* defName = "Onegin.txt";
    if(c == 2)
    {
        fName = v[1];
        return 0;
    }
    else if(c > 2)
    {
        fprintf(stderr, "Too many console arguments, they will be ignored.\n");
        fName = defName;
        return TOO_MANY_CARGS;
    }
    else
    {
        fName = defName;
        return 0;
    }
}

