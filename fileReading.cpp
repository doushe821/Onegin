#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "OneginIO.h"
#include "SoftAssert.h"

int readFromFile(struct Text* text, const char* fileName)
{
    FILE* fp = fopen(fileName, "rb");
    if(fp == NULL)
    {
        perror("fopen()");
        return FOPEN_ERROR;
    } 

    fseek(fp, 0L, SEEK_END);
    text->bufferLen = ftell(fp);
    rewind(fp);

    fprintf(stderr, "bufferLen = %d\n", text->bufferLen);

    text->buffer = (char*)calloc(text->bufferLen + 1, sizeof(char));
    text->buffer[text->bufferLen] = '\n';

    if(fread(text->buffer, text->bufferLen, sizeof(*text->buffer), fp) == NULL)
    {
        perror("fread()");
        return FREAD_ERROR;
    }


    for(int i = 0; i < text->bufferLen + 1; i++)
    {
        if(strchr(text->buffer + i + 1, '\n') != NULL)
        {
            i += strchr(text->buffer + i + 1, '\n') - (text->buffer + i);                
            text->nLines++;        
        }
    }

    fprintf(stderr, "nlines = %d\n", text->nLines);

    text->lines = (char**)calloc(text->nLines + 1, sizeof(text->lines));

    int ptrIndex = 0;
    FILE* db = fopen("debug.txt", "w+b");
    for(size_t i = 0; i < text->bufferLen + 1; i++)
    {
        char* stringEndPtr =  strchr(text->buffer + i, '\n');
        if(stringEndPtr != NULL)
        {
            *stringEndPtr = '\0';
            text->lines[ptrIndex] = text->buffer + i;
            i += stringEndPtr - (text->buffer + i);
            ptrIndex++;
        }
    }

    fclose(fp);
    fclose(db);
    return 0;
}

void freeOnegin(struct Text* text)
{
    free(text);
}



int getFileName(int c, char** v, char* fName)
{
    char defName [11] = "Onegin.txt";
    if(c == 2)
    {
        fName = v[1];
        return 0;
    }
    else if(c > 2)
    {
        fprintf(stderr, "Too many console arguments, all will be ignored.\n");
        fName = defName;
        return TOO_MANY_CARGS;
    }
    else
    {
        fName = defName;
        return 0;
    }
}

void errParse()
{

}