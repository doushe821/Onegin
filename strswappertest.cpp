#include <stdio.h>

int main()
{
    char str1[3] = "23";
    char str2[3] = "65";

    for(int i = 0; i < 2; i++)
    {
        char c = str2[i];
        str2[i] = str1[i]; 
        str1[i] = c;
    }
    fprintf(stderr, "%s,    %s", str1, str2);

}