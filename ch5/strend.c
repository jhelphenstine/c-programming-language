#include <stdio.h>
#include <string.h> /* for strlen */
#include "reverse.c"

/* strend.c: report if str s ends with str t */
int strend(char *s, char *t);
void reverse(int length, char *target, int start);

int main(){
    char first[] = "Testing, 1, 2, 3";
    char second[] = "1, 2, 3";
    reverse(strlen(first), first, 0);
    reverse(strlen(second), second, 0);
    int result = strend(first, second);
    printf("Results (1 = match; 0 = no match): %d\n", result);
    return 0;
}

int strend(char *s, char *t){
    int result = 0;
    for(int i = 0; i < strlen(t); i++){
        if(s[i] == t[i]){
            result = 1;
        }
        else {
            result = 0;
        }
    }
    return result;
}