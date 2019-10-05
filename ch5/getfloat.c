#include <stdio.h>
#include <ctype.h>
#include "getch.c"
#include <math.h> /* for pow */

int getch(void);
void ungetch(int);
int getfloat(float *pn);

int main(){
    float x = 0;
    int ret = 0;
    while ((ret = getfloat(&x)) != EOF){
        if(ret != 0){
            printf("Float: %f\n", x);
        }
    }
    return 0;
}

/* getfloat: get next integer from input into *pn */
int getfloat(float *pn)
{
    int c, sign;

    while(isspace(c = getch())){
        ; /* skip whitespace */
    }

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c); /* not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-'){
        c = getch(); /* skip past signs */
        if (!isdigit(c)){
            sign = 1; /* ensure we don't carry forward a negation */
            return 0; /* + or - must be followed by a digit */
        }
    }
    /* get mantissa */
    for(*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }
    /* check for decimal point */
    if(c == '.'){
        int multiplier = 1;
        c = getch();
        for(; isdigit(c); c = getch()){
            *pn += (c - '0') * (1.0 / (pow(10, multiplier++)));
        }
    }

    *pn *= sign;
    if(c != EOF){
        ungetch(c); /* Not EOF; push it back */
    }
    return c;
}