#include <stdio.h>
#include "sort.h"   /* we're going to break this project up */

#define MAXLINES 4   /* max #lines to be sorted */

/* pointer to text lines */
char *lineptr[MAXLINES];

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr , nlines);
        return 0;
    }
    else {
        printf("[!] Error: Input too big to sort\n");
        return 1;
    }
}