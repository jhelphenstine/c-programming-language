/* read lines for sorting */
/* @params: char *  pointer to array of pointers
            int     number of lines to read

    @return: int    number of lines read */
int readlines(char *[], int);

/* write output lines */
/* @params: char *  pointer to array of pointers
            int     number of lines to write */
void writelines(char *[], int);

/* qsort: sort an array of arrays */
/* @params: char *  pointer to array of pointers
            int     left element
            int     right element */
void qsort(char *[], int, int);

/* getline: get a line of input */
int getline_p(char *, int);

char *alloc(int n);  /* return pointer to n characters */

void afree(char *p); /* free storage pointed to by p */
