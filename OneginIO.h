#ifndef ONEGIN_IO_INCLUDED
#define ONEGIN_IO_INCLUDED
#include <limits.h>

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

void readFromFile(struct Text* text, const char* fileName);
int fstrcmp(void* a, void* b);
void ptrSwap(char** ptr1, char** ptr2, size_t size);
void bubSort(struct Text* text);

#endif