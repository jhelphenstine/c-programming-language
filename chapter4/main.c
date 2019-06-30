#include <stdio.h>
#include <stdlib.h>	/* for atof.h */
#include <math.h>	/* for fmodf. I'll pass on implementing that. */
#include <stdbool.h>	/* for flags */
#include <ctype.h>		/* for toupper */
#include "calc.h"

#define MAXOP 100	/* max size of operand or operator */

bool sig_clear = false; /* signal to clear stack */
bool sig_variable = false; /* initialize is-a-variable flag */
int mem_index = -1;	/* initialize reference within memory[] */
bool dereference = false;	/* define pop() behavior */

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
			printf("main.c, case NUMBER: I'm pushing %f\n", atof(s) * sign);
			printf("main.c, case NUMBER: I'm setting sig_variable to false\n");
			sig_variable = false;
			push((atof(s)) * sign); /* push the correctly signed value */
			sign = 1;
			bypass = true;
			break;

		/* Special variable: refers to last value on stack. I'm sure
			this won't cause me any heartache... */
		case '$':
			// WIP; first, commit what works, DBG messages and all.
			break;

		/* BEGIN OPERATIONS */
		case '+':
			dereference = true;
			push(pop() + pop());
			bypass = false;
			break;
		case '*':
			dereference = true;
			push(pop() * pop());
			bypass = false;
			break;
		case '-':
			dereference = true;
			op2 = pop();
			push(pop() - op2);
			bypass = false;
			break;
		case '/':
			dereference = true;
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
			dereference = true;
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
			dereference = true;
			op2 = sin(pop());
			push(op2);
			bypass = true;	/* I think we don't want to cash out immediately */
			printf("[*] Pushing sin value to stack: %g\n", op2);
			break;
		/* Exercise 4-5 Part II: provide natural log function */
		case '`':
			dereference = true;
			op2  = log(pop());
			push(op2);
			bypass = true;
			printf("[*] Pushing natural log to stack: %g\n", op2);
			break;
		case '^':
			dereference = true;
			op2 = pop();
			op1 = pop();
			if((op1 == 0) && (op2 <= 0)){
				printf("[!] Domain error! Cannot raise 0 to less than 0.\n");
				sig_clear = true;
			}
			else if ((op1 < 0) && (ceil(op2) != op2)){
				printf("[!] Domain error! Cannot raise negative to\
						 non-integer power.\n");
				sig_clear = true;
			}
			else {
				push(pow(op1, op2));
			}
			bypass = false;
			break;
		case '=':
			/* '=' is our assignment operator. This means, put op1 into the 
				memory space referred to by op2. Requirements: op2 must refer
				to a space in memory[]; op1 must be NOT (else we open ourselves
				to endless dereferencing */
			dereference = false;	/* Don't dereference */
			op2 = pop();	/* pop op2. If popping a var, flag will be set */
			if (sig_variable){
				sig_variable = false;
				op1 = pop();	/* pop op1; this cannot be a variable */
				if(sig_variable){
					printf("[!] Error! Cannot assign variables to variables.\n");
					bypass = true;
					break;
				}
				else {
					/* We will assign op1 to the memory referred to by op2 */
					/* convert op2 to index value == subtract 'A' */
					printf("main.c, case =: op2 is: %g; will set to  %g - 'A'\n", op2, op2);
					mem_index = ((int)op2 - 'A');
					printf("main.c, case =: I set mem_index to %d\n", mem_index);
					push(op1);	/* We've set mem_index, push the value */
					bypass = true;
					sig_clear = true; /* clear the stack */
					printf("main.c, case =: Triggering stack clear\n");
					push(0.0);	/* trigger stack clear */
					break;
				}
			}
			else { /* This isn't a variable; we can't assign to it */
				printf("[!] Error! Cannot assign to non-variable: %g\n", op2);
				bypass = true;
				break;
			}

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
				/* DEBUG: Let's look at memory[] */
				printf("Memory: ");
				for (int i = 0; i < 26; i++){
					printf("%g ", memory[i]);
				}
				printf("\n");
				sig_clear = true;
				push(0);	/* triggers stack clear because sig_clear is set */
			}
			bypass = false;
			break;
		default:
		/* If we've received a variable ([A-Z]||[a-z])||$ */
		/* This isn't the same as handling '='; this is just correctly storing
			variable letters. Since case tests must be compile-time constants,
			we're handling this in the default case. */
			if(('A' <= toupper(s[0])) && (toupper(s[0]) <= 'Z')){
				s[0] = toupper(s[0]);
				printf("main.c: We received a letter\n");
				printf("main.c: s[0] is: %d\n", toupper(s[0]));
				sig_variable = true;	/* treat this as a variable */
				push((double)s[0]);
				bypass = true;
				break;
			}
			printf("[!] Error, unknown command: %s\n", s);
			break;
		}
	}
	return 0;
}
