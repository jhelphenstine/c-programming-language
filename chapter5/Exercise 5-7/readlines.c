#include <string.h>
#include "sort.h"

#define MAXLEN 1000 /* max length of any input line */

char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;        /* nlines = number of lines we're storing */
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline_p(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p = alloc(len)) == NULL){
            return -1;  // Error; can't read any more lines
        }
        else {
            line[len-1] = '0'; /* delete newlines */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}