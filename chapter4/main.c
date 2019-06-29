#include <stdio.h>
#include <stdlib.h>	/* for atof.h */
#include <math.h>	/* for fmodf. I'll pass on implementing that. */
#include "calc.h"

#define MAXOP 100	/* max size of operand or operator */
#define TRUE 1
#define FALSE 0

int sig_clear = FALSE; /* signal to clear stack */

/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	int bypass = FALSE;	/* bypass standard newline behavior */

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push((atof(s)) * sign); /* push the correctly signed value */
			sign = 1;
			bypass = TRUE;
			break;
		case '+':
			push(pop() + pop());
			bypass = FALSE;
			break;
		case '*':
			push(pop() * pop());
			bypass = FALSE;
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			bypass = FALSE;
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0){
				push(pop() / op2);
			}
			else{
				printf("[!] Error, cannot divide by zero\n");
			}
			bypass = FALSE;
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
			bypass = FALSE;
			break;
		/* Exercise 4-3 Part II: Extend calculator to handle signed values */
		case '&':
			/* & is our NOP; part of how we handle negative variables */
			break;
		/* Exercise 4-4 Part I: Show last push val without popping */
		case '?':
			printf("[*] Last pushed val is: %g\n", lastVal);
			bypass = TRUE;
			break;
		/* Exercise 4-4 Part II: Duplicate last stack item (re-push) */
		case '!':
			printf("[*] Duplicating last stack value: %g\n", lastVal);
			push(lastVal);
			bypass = TRUE;
			break;
		/* Exercise 4-3 Part III: Swap the stack */
		case '#':
			op2 = pop();
			double op1 = pop(); /* declaring it here as it's only used here */
			printf("[*] Old stack: %g, %g\n", op1, op2);
			push(op2);
			push(op1);
			printf("[*] New stack: %g, %g\n", op2, op1);
			bypass = TRUE;
			break;
		/* Exercise 4-4 Part IV: Clear the stack */
		case '@':
			sig_clear = TRUE;
			push(0);
			printf("[*] Stack cleared!\n");
			bypass = TRUE;
			break;
		case '\n':
			if (!bypass){
				printf("[*] Result: \t%.8g\n", pop());
				sig_clear = TRUE;
				push(0);	/* triggers stack clear because sig_clear is set */
			}
			bypass = FALSE;
			break;
		default:
			printf("[!] Error, unknown command: %s\n", s);
			break;
		}
	}
	return 0;
}
