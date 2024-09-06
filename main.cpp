#include <stdio.h>
#include <ctype.h>

enum errorCodes
{
    FOPEN_ERROR = -1,
}; //TODO errno

const size_t STRING_NUMBER = 14;
const size_t STRING_LENGTH = 88;

void StringSwapper(char* str1, char* str2);
void SortText(char text[14][100]);

int main()
{
    FILE* fp = fopen("Onegin.txt", "r");
    if(fp == NULL)
        return FOPEN_ERROR;

    char text[STRING_NUMBER][STRING_LENGTH] = {};
    for(int i = 0; i < STRING_NUMBER; i++)
    {
        fgets(text[i], STRING_LENGTH, fp); //TODO: fread, small freading library.
    }

    SortText(text);

    for(int i = 0; i < STRING_NUMBER; i++)
    {
        fprintf(stderr, "%s", text[i]);
    }
    fclose(fp);
}

void StringSwapper(char* str1, char* str2)
{
    for(int i = 0; i < STRING_LENGTH; i++)
    {
        char c = str2[i];
        str2[i] = str1[i]; 
        str1[i] = c;
    }
}

void SortText(char text[14][88])
{
    for(int k = 0; k < STRING_NUMBER; k++)
    {
        for(int i = 0; i < STRING_NUMBER - 1; i++)
        {
            for(int j = 0; j < STRING_LENGTH && text[i][j] != '\0'; j++)
            {
                if(text[i][j] - text[i+1][j] > 0)
                {
                    StringSwapper(text[i], text[i+1]);
                    break;
                }
                else if(text[i][j] - text[i+1][j] == 0)
                {
                    continue;
                }
                else
                    break;
            }
        }
    }
}