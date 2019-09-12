#include <stdio.h>
#include "sort.h"   /* we're going to break this project up */

#define BUFFSIZE 10000
#define MAXLINES 5000   /* max #lines to be sorted */

/* pointer to text lines */
char *lineptr[MAXLINES];

static char buff[BUFFSIZE];    /* storage buffer */
static char *buffp = buff;     /* next free position in our storage buffer */

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */

    if((nlines = readlines(lineptr, MAXLINES, allocp)) >= 0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr , nlines);
        return 0;
    }
    else {
        printf("[!] Error: Input too big to sort\n");
        return 1;
    }
}