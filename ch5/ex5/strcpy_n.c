#include <stdio.h>
#include <string.h>
#define MAX 100

/* strcpy_n: copy n bytes of string t to string s, including '\0' */
/* replicates behavior of "strncpy", as opposed to "strcpy" */
char * strcpy_n(char *s, char *t, int n);

int main()
{
    char first[MAX]; /* this can't already have a value assigned to it */
    char second[]="Hello";
    int num_bytes = 3;
    char * new = strcpy_n(first, second, num_bytes);
    printf("After strcpy of up to %d bytes: %s\n", num_bytes, new);
    return 0;
}

char * strcpy_n(char *s, char *t, int n)
{
    int length = (strlen(s) < n) ? strlen(s) : n;
    int i;
    for(i = 0; i < length; i++){
        s[i] = t[i];
    }
    s[i] = '\0';
    return s;
}