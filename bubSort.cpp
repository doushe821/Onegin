#include "OneginIO.h"
#include <stdio.h>

void bubSort(struct Text* text, int (*comp)(const void*, const void*))
{
    //fprintf(stderr, "hi\n");
    for(size_t i = 0; i < text->nLines; i++)
    {
        for(size_t j = 0; j < text->nLines - i - 1; j++)
        {
            if(comp((void*)text->lines[j], (void*)text->lines[j+1]) == 1)
            {
                ptrSwap(&text->lines[j], &text->lines[j+1], sizeof(&text->lines));
            }
            else 
            {
                //fprintf(stderr, "%zu\n", j);
            }
        }
    }
}