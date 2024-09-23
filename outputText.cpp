#include "OneginIO.h"

int outputSortedText(struct Text* text, const char* fName, const char* mode)
{
    FILE* fop = fopen("sorted", "w+b"); 
    if(fop == NULL)
    {
        perror("fopen()");
        errParse(FOPEN_ERROR);
    }
    
    for(size_t i = 0; i < text->nLines; i++)
    {
        //fprintf(stderr, "%s\n", text->lines[i].ptr);
        fprintf(fop, "%s\n", text->lines[i].ptr);
    } 
    fclose(fop);
    return 0;
}