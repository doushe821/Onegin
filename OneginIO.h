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
    char* unsortedCopy;
};

void readFromFile(struct Text* text, const char* const fileName);
void writeToFile(struct Text* sorted, const char* const fileName);
int fstrcmp(void* a, void* b);
int bstrcmp(void* a, void* b);
void ptrSwap(char** ptr1, char** ptr2, size_t size);
void bubSort(struct Text* text, int (*comp)(void*, void*));
int outputSortedText(struct Text* text, const char* fName);

#endif