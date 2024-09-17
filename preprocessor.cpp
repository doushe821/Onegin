#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

const char* fName = "Onegin.txt"
const char* output = "processed" + fName;

int cleanseText()
{
    FILE* fpIn = fopen(fName, "r+b");

    if(fpIn == NULL)
        return -1;

    fseek(fpin, 0L, SEEK_END);
    size_t size = ftell(fpIn);
    rewind(fpIn);

    FILE* fpOut = fopen(output, "w+b");
    if(fpIn == NULL)
        return -1;
    
    bool sFlag = 0;
    int p = 0;
    for(int i = 0; i < size; i++)
    {
        int c = fgetc(fpIn);
        if((c == '\n' || c == '\0' || c == '\p') && !Flag)
            continue;
        else
            fputc(fpOut);
    }
    
    return 0;
}