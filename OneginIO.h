#ifndef ONEGIN_IO_INCLUDED
#define ONEGIN_IO_INCLUDED
#include <limits.h>
#include <string.h>
#include <stdio.h>

enum errors
{
    FREAD_ERROR = 1,
    FOPEN_ERROR, 
    TOO_MANY_CARGS,
};

struct Line
{
    char* line
    size_t length
};

struct Text
{
    char* buffer;
    size_t bufferLen;
    struct Line*;
    size_t nLines;
};

void errParse();
int getFileName(int c, char** v, char* fName);
int readFromFile(struct Text* text, const char* const fileName);
void writeToFile(struct Text* sorted, const char* const fileName);
int strcmpForwards(const void* a, const void* b);
int strcmpBackwards(const void* a, const void* b);
int outputSortedText(struct Text* text, const char* fName, const char* mode);
void freeOnegin(struct Text* text);

#endif