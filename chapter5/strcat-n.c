#include <stdio.h>
#include <string.h> /* for strlen */

#define MAX 1000

/* strcat_n(s,t,n): copy string t to the end of s, up to n bytes*/
char * strcat_n(char *s, char *t, int n);

int main(){
    char s[] = "Hello ";
    char t[] = "World!";
    int n = 3;
    char * p = strcat_n(s,t,n);
    printf("Returned was: %s\n", p);
    return 0;
}

char * strcat_n(char *s, char *t, int n){
    size_t length_s = (strlen(s) < n) ? strlen(s) : n;
    size_t length_t = (strlen(t) < n) ? strlen(s) : n;
    static char new[MAX];
    size_t i;
    for(i = 0; i < length_s; i++){
        new[i] = s[i];
    }
    for(size_t j = 0; j < length_t; j++){
        new[i++] = t[j];
    }
    return new;
}