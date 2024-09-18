#ifndef ONEGIN_IO_INCLUDED
#define ONEGIN_IO_INCLUDED
#include <limits.h>
#include <string.h>
#include <stdio.h>

struct Line
{
    char* ptr;
    size_t length;
};

struct Text
{
    char* buffer;
    size_t bufferLen;
    struct Lines* lines;
    size_t nLines;
};

void readFromFile(struct Text* text, const char* const fileName);
void writeToFile(struct Text* sorted, const char* const fileName);
int strcmpForwards(const void* a, const void* b);
int strcmpBackwards(const void* a, const void* b);
int outputSortedText(struct Text* text, const char* fName, const char* mode);
void freeDynamicMem(struct Text* text);

#endif