#include <stdio.h>
#include <ctype.h>

/* atoi: convert string s to integer using atof */
int atoi(char *s);


int main()
{
    char *test = "123";
    printf("Result: %d\n", atoi(test));
    return 0;
}

int atoi(char *s)
{
    int n, sign;    /* no need for int i as an iterator */
    char *p;    /* this lets us work with pointer arithmetic over indices */

    p = s;

    /* advance past whitespace */
    while(isspace(*p)){
        p++;
    }
    
    /* preserve sign */
    sign = (*p == '-') ? -1 : 1;
    
    /* skip over + or - sign */
    if (*p == '+' || *p == '-'){
        p++;
    }
    
    /* build out our answer. multiplying by 10 effectively 'shifts' n to
        the left, inserting our next digit into the one's place. */
    for (n = 0; isdigit(*p); p++){
        n = 10 * n + (*p - '0');
    }

    /* return our appropriately signed result */
    return sign * n;
}