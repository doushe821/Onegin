#include "OneginIO.h"
#include <stdio.h>

void bubSort(struct Text* text)
{
    fprintf(stderr, "hi\n");
    for(size_t i = 0; i < text->nLines; i++)
    {
        //for(int g = 0; g < text->nLines; g++)
           // fprintf(stderr, "%s\n", text->lines + g);
        fprintf(stderr, "i = %zu\n", i);
        fprintf(stderr, "%d\n", text->nLines);
        for(size_t j = 0; j < text->nLines - i - 1; j++)
        {
            if(fstrcmp((void*)text->lines[j], (void*)text->lines[j+1]) == 1)
            {
                ptrSwap(&text->lines[j], &text->lines[j+1], sizeof(&text->lines));
            }
            else 
            {
                fprintf(stderr, "%zu\n", j);
            }
        }
    }
}