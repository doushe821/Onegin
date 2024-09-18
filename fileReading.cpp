#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "OneginIO.h"
#include "SoftAssert.h"

void readFromFile(struct Text* text, const char* fileName)
{
    FILE* fp = fopen(fileName, "rb");
    if(fp == NULL)
    {
        perror("fopen()");
        cAssert(0, "File opening error.");
    } 

    fseek(fp, 0L, SEEK_END);
    text->bufferLen = ftell(fp);
    rewind(fp);

    fprintf(stderr, "bufferLen = %d\n", text->bufferLen);

    text->buffer = (char*)calloc(text->bufferLen + 2, sizeof(char));
    text->buffer[0] = '\0';
    text->buffer[text->bufferLen] = '\0';

    if(fread(text->buffer + 1, text->bufferLen, sizeof(*text->buffer), fp))
    {
        perror("fread()");
        cAssert(0, "File reading error.");
    }


    for(size_t i = 0; i < text->bufferLen; i++)
    {
        if(text->buffer[i] == '\n')
            text->nLines++;
    }
    text->nLines++; // cycle doesn't count first line
    fprintf(stderr, "nlines = %d\n", text->nLines);

    text->lines = (char**)calloc(text->nLines + 1, sizeof(text->lines));

    int ptrIndex = 0;
    for(size_t i = 0; i < text->bufferLen; i++)
    {
        if(text->buffer[i] == '\r')
        {
            text->buffer[i] = '\0';
            continue;
        }
        if(text->buffer[i] == '\n' || text->buffer[i] == '\0')
        {
            text->buffer[i] = '\0';
            text->lines[ptrIndex++] = (text->buffer + i + 1);
            i++;
        }
    }

    //TODO TODO TODO use strchr
    /*fprintf(stderr, "PTRINDEX: %d\n", ptrIndex);
    for(int i = 0; i < ptrIndex; i++)
        fprintf(stderr, "%s\n", text->lines[i]);
    */
}
