#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "OneginIO.h"
#include "SoftAssert.h"

struct Text Onegin = {0, 0, 0, 0, 0};
 
int main()
{  
    readFromFile(&Onegin, "fullOnegin.txt");

    bubSort(&Onegin, &fstrcmp);
    outputSortedText(&Onegin, "Sorted.txt");
    printf("Sorting forward done.\n");

    bubSort(&Onegin, &bstrcmp);
    outputSortedText(&Onegin, "Sorted.txt");
    printf("Backward sorting is done, enjoy new rhymes!");
   // wqsort(tArr.ptrs, tArr.fSize, sizeof(char**), &wstrcmp( ));


    free(Onegin.lines);
    free(Onegin.buffer);
}



