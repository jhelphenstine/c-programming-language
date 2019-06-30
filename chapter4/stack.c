#include <stdio.h>
#include <stdbool.h>
#include "calc.h"
#define MAXVAL 100	/* maximum depth of val stack */

int sp = 0;			/* next free stack position */
double val[MAXVAL] = {0};	/* value stack */
double lastVal = 0.0;	/* define lastVar */

/* push: push f onto value stack */
void push(double f)
{
	/* Check to see if we should clear the stack */
	if (sig_clear == 1){
		for (int i = 0; i < sp; i++){
			val[i] = 0.0;	/* zero out val */
		}
		sig_clear = false;	/* reset the clear flag */
	}
	else if(sp < MAXVAL){
		val[sp++] = f;
		lastVal = f;
	}
	else {
		printf("[!] Error: Stack full! Cannot push %g\n", f);
	}
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0){
		return val[--sp];
	}
	else {
		printf("[!] Error: Stack empty!\n");
		return 0.0;
	}
}
