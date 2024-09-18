#ifndef ONEGIN_IO_INCLUDED
#define ONEGIN_IO_INCLUDED
#include <limits.h>
#include <string.h>
#include <stdio.h>

enum errorCodes
{
    FOPEN_ERROR = -1,
    READING_ERROR = -2
}; //TODO errno

struct Text
{
    char* buffer;
    size_t bufferLen;
    char** lines;
    size_t nLines;
};

void readFromFile(struct Text* text, const char* const fileName);
void writeToFile(struct Text* sorted, const char* const fileName);
int fstrcmp(const void* a,const void* b);
int bstrcmp(const void* a, const void* b);
int outputSortedText(struct Text* text, const char* fName, const char* mode);

#endif