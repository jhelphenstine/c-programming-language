#include <stdio.h>
#include <string.h>

void reverse(int length, char target[]);
char test[]="20904";

static int x = 0;

/* reverse-r: reverse a string using recursion */

int main(){
    printf("Test string: %s\n", test);
    int length = strlen(test);
    reverse(length, test);
    printf("Reversed: %s\n", test);
    return 0;
}

void reverse(int length, char target[]){
    if(x < (length/2)){
        /* We aren't past the halfway mark yet */
        char swap;
        swap = target[x];
        target[x] = target[length-(x+1)];
        target[length-(x+1)] = swap;
        x++;
        reverse(length, target);
    }
    else{
        return;
    }
}