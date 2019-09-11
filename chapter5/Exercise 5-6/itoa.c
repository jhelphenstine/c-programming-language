#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "reverse.c"

#define MAX 100
#define TEST 123456

/* itoa: convert integer to string */
char * itoa(char * result, int i);

int main(){
    int test = TEST;
    char buffer[MAX];
    char * ptr = buffer;
    printf("Result returned from itoa(): %s\n", itoa(ptr, test));
    return 0;
}

char * itoa(char * result, int i)
{
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
    while ((c = (*p / x))){
        *presult = c + '0';
        *p -= x * c;    /* remove a digit from p */
        presult++;
        x/=10;
        if(x == 0){
            break; /* can't have a divide by zero condition */
        }
    }
    *presult = '\0';
    return result;
}