#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "OneginIO.h"
#include "SoftAssert.h"

struct Text Onegin = {0, 0, 0, 0};
 
int main()
{  
    readFromFile(&Onegin, "Onegin.txt");
    bubSort(&Onegin);
    whisper("hi main\n");
    for(int i = 0; i < Onegin.nLines; i++)
    {
        printf("%s\n", Onegin.lines[i]);
    } 

   // wqsort(tArr.ptrs, tArr.fSize, sizeof(char**), &wstrcmp( ));


    free(Onegin.lines);
    free(Onegin.buffer);
}



