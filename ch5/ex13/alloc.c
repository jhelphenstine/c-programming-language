#include <stdlib.h>
#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char * alloc(size_t n)  /* return pointer to n characters */
{
    if((size_t)(allocbuf + ALLOCSIZE - allocp) >= n){
        /* it fits */
        allocp += n;    /* set allocp for next call */
        return allocp -n;   /* old p */
    }
    else {
        /* not enough room */
        return 0;
    }
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE){
        allocp = p;
    }
    return;
}