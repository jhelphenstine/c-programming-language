#include <stdio.h>
#include <ctype.h>
#include "getch.c"

int getch(void);
void ungetch(int);
int getint(int *pn);

int main(){
    int x = 0;
    int ret = 0;
    while ((ret = getint(&x)) != EOF){
        if(ret != 0){
            printf("Integer: %d\n", x);
        }
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while(isspace(c = getch())){
        ; /* skip whitespace */
    }

    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
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
    for(*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if(c != EOF){
        ungetch(c); /* Not EOF; push it back */
    }
    return c;
}