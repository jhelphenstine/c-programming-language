#include <stdio.h>
#include <stdlib.h>	/* for atof.h */
#include <math.h>	/* for fmodf. I'll pass on implementing that. */
#include <stdbool.h>	/* for flags */
#include "calc.h"

#define MAXOP 100	/* max size of operand or operator */

bool sig_clear = false; /* signal to clear stack */

/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	double op1; /* This is now useful as I've used it in 2 cases */
	char s[MAXOP];
	bool bypass = false;	/* bypass standard newline behavior */

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push((atof(s)) * sign); /* push the correctly signed value */
			sign = 1;
			bypass = true;
			break;

		/* BEGIN OPERATIONS */
		case '+':
			push(pop() + pop());
			bypass = false;
			break;
		case '*':
			push(pop() * pop());
			bypass = false;
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			bypass = false;
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0){
				push(pop() / op2);
			}
			else{
				printf("[!] Error, cannot divide by zero\n");
			}
			bypass = false;
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
			bypass = false;
			break;
		/* Exercise 4-5 Part I: provide sin() function */
		case '~':
			op2 = sin(pop());
			push(op2);
			bypass = true;	/* I think we don't want to cash out immediately */
			printf("[*] Pushing sin value to stack: %g\n", op2);
			break;
		/* Exercise 4-5 Part II: provide natural log function */
		case '`':
			op2  = log(pop());
			push(op2);
			bypass = true;
			printf("[*] Pushing natural log to stack: %g\n", op2);
			break;
		case '^':
			op2 = pop();
			op1 = pop();
			if((op1 == 0) && (op2 <= 0)){
				printf("[!] Domain error! Cannot raise 0 to less than 0.\n");
				sig_clear = true;
			}
			else if ((op1 < 0) && (ceil(op2) != op2)){
				printf("[!] Domain error! Cannot raise negative to non-integer power.\n");
				sig_clear = true;
			}
			else {
				push(pow(op1, op2));
			}
			bypass = false;
			break;
		/* END OPERATIONS */

		/* BEGIN CONTROL CODES */
		/* Exercise 4-3 Part II: Extend calculator to handle signed values */
		case '&':
			/* & is our NOP; part of how we handle negative variables */
			break;
		/* Exercise 4-4 Part I: Show last push val without popping */
		case '?':
			printf("[*] Last pushed val is: %g\n", lastVal);
			bypass = true;
			break;
		/* Exercise 4-4 Part II: Duplicate last stack item (re-push) */
		case '!':
			printf("[*] Duplicating last stack value: %g\n", lastVal);
			push(lastVal);
			bypass = true;
			break;
		/* Exercise 4-3 Part III: Swap the stack */
		case '#':
			op2 = pop();
			op1 = pop();
			printf("[*] Old stack: %g, %g\n", op1, op2);
			push(op2);
			push(op1);
			printf("[*] New stack: %g, %g\n", op2, op1);
			bypass = true;
			break;
		/* Exercise 4-4 Part IV: Clear the stack */
		case '@':
			sig_clear = true;
			push(0);
			printf("[*] Stack cleared!\n");
			bypass = true;
			break;
		/* END CONTROL CODES */

		case '\n':
			if (!bypass){
				printf("[*] Result: \t%.8g\n", pop());
				sig_clear = true;
				push(0);	/* triggers stack clear because sig_clear is set */
			}
			bypass = false;
			break;
		default:
			printf("[!] Error, unknown command: %s\n", s);
			break;
		}
	}
	return 0;
}
