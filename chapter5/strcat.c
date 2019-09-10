#include <stdio.h>
#include <string.h> /* for strlen */

#define MAX 1000

/* strcat_p(s,t): copy string t to the end of s */
char * strcat_p(char *s, char *t);

int main(){
    char s[] = "Hello ";
    char t[] = "World!";
    char * p = strcat_p(s,t);
    printf("Returned was: %s\n", p);
    return 0;
}

char * strcat_p(char *s, char *t){
    size_t length_s = strlen(s);
    size_t length_t = strlen(t);
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