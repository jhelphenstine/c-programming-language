#include <stdio.h>

void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0){
        printf("%s\n", *lineptr++);
    }
}