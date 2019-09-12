#include <stdio.h>
#include <string.h>


void reverse(int length, char target[], int x);
void reverse_p(int length, char *target);

int main()
{
    char test[] ="Hello World!";
    reverse_p(strlen(test), test);
    printf("Reversed: %s\n", test);
    return 0;
}

/* reverse: reverse a string
    @params:    int length      -- strlen() results
                char *target    -- string to reverse
                int start       -- position to start from (usually 0)
*/
void reverse(int length, char target[], int x){
    if(x < (length/2)){
        /* We aren't past the halfway mark yet */
        char swap;
        swap = target[x];
        target[x] = target[length-(x+1)];
        target[length-(x+1)] = swap;
        (x)++;
        reverse(length, target, x);
    }
    else{
        return;
    }
}

/* reverse: reverse a string
    @params:    int length      -- strlen() results
                char *target    -- string to reverse

    This version uses pointers, but is not recursive.
*/
void reverse_p(int length, char *target)
{
    char *ptarget_a;
    char *ptarget_b;
    char swap;
    for (int i = 0; i < length/2; i++){
        ptarget_a = (target + i);
        ptarget_b = (target + length - (i + 1)); /* minus 1 for NULL at end */
        swap = *ptarget_b;
        *ptarget_b = *ptarget_a;
        *ptarget_a = swap;
    }
    return;
}