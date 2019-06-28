#include <stdio.h>
#include <stdlib.h>	/* for atof.h */
#include <math.h>	/* for fmodf. I'll pass on implementing that. */
#include "calc.h"

#define MAXOP 100	/* max size of operand or operator */

/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push((atof(s)) * sign); /* push the correctly signed value */
			sign = 1;
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0){
				push(pop() / op2);
			}
			else{
				printf("[!] Error, cannot divide by zero\n");
			}
			break;
		/* Exercise 4-3 Part I: Extend calculator to include % operator */
		case '%':
			op2 = pop();
			if (op2 != 0.0){
				push(fmodf(pop(), op2));
			}
			else {
				printf("[!] Error, cannot divide by zero\n");
			}
			break;
		/* Exercise 4-3 Part II: Extend calculator to handle signed values */
		case '&':
			/* & is our NOP; part of how we handle negative variables */
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("[!] Error, unknown command: %s\n", s);
			break;
		}
	}
	return 0;
}
