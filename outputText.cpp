#include "OneginIO.h"

int outputSortedText(struct Text* text, const char* fName, const char* mode)
{
    FILE* fop = fopen(fName, mode); 
    if(fop == NULL)
    {
        perror("fopen()");
        errParse(FOPEN_ERROR);
    }
    
    for(size_t i = 0; i < text->nLines; i++)
    {
        fprintf(fop, "\n%s\n", text->lines[i].ptr);
    } 
    fclose(fop);
    return 0;
}