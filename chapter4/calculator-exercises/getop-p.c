#include <ctype.h>
#include <string.h>
#include <stdio.h> /* for debugging */
#include "calc.h"

#define MAXINPUT 100 /* that's all we'll allow */

/* getop: return a numeric operand or operator */
/* from calc.h: NUMBER is defined as '0', signifies
	we've placed a numeric operand into the provided
	character array */
/* Called by:
	main.c - main()
	*/

static char input[MAXINPUT] = {0};
static char *pi = input;   /* pointer into received input */
int sign = 1;

int getop(char *s)
{
    /* check for stack clear */
	if(sig_stack_cleared){
		pi = input;
		sign = 1;
		sig_stack_cleared = false;
	}

    char *ps = s;    /* pointer into our provided buffer */

    /* get input if our buffer pointer is at index 0 */
    if(pi == input){
        getLine(pi, MAXINPUT);
    }

    /* advance past whitespace */
    while ((*pi == ' ') || (*pi == '\t')){
        pi++;
    }

    /* check for sign */
    if(*pi == '-'){
        char *peek = pi + 1;
        if(isdigit(*peek)){
            sign *= -1;
            pi++;
        }
    }

    /* need to test for is operand or is operator */
    if(!isdigit(*pi) && (*pi != '.')){
        *ps++ = *pi;
        *ps = 0;    /* terminating null */
        return *pi++;   /* not a number, not a decimal point */
    }

    /* collect integer portion */
    while (isdigit(*pi)){
        *ps++ = *pi++;
    }

    /* check for decimal point; if present, collect fractional part */
    if(*pi == '.'){
        *ps = '.';
        while (isdigit(*pi)){
            *ps++ = *pi++;
        }
    }
    *ps = 0; /* null terminator */
    return NUMBER;

}