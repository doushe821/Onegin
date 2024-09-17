#include "OneginIO.h"

int outputSortedText(struct Text* text, const char* fName, const char* mode)
{
    FILE* fp = fopen(fName, mode); 
    if(fp == NULL)
    {
        return -1; //TODO
    }
    for(int i = 0; i < text->nLines; i++)
    {
        fprintf(fp, "%s\n", text->lines[i]);
    } 
    return 0;
}