#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "reverse.c"

#define MAX 100
#define TEST 123456

/* itoa: convert integer to string */
char * itoa(int i);

int main(){
    int test = TEST;
    char * result = itoa(test);
    printf("Result: %s\n", result);
    return 0;
}

char * itoa(int i)
{
    char result[MAX];
    char *presult;
    presult = result;
    int *p = &i;
    
    /* determine what our starting power of 10 is */
    int x = 1;
    while (*p >= (x * 10)) {
        x*=10;
    }

    /* Extract our characters */
    int c;
    while (c = (*p / x)){
        *presult = c + '0';
        *p -= x * c;    /* remove a digit from p */
        presult++;
        x/=10;
        if(x == 0){
            break; /* can't have a divide by zero condition */
        }
    }
    *presult = '\0';
    presult = result;
    /* If the following line is commented out, main will not print a result. */
    printf("DBG: result = %s\n", result);
    return presult;
}