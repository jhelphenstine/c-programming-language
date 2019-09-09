#include <stdio.h>
#include <string.h> // for memset
#include <ctype.h>
#include "calc.h"

#define MAXINPUT 100 /* that's all we'll allow */

/* getop: return a numeric operand or operator */
/* from calc.h: NUMBER is defined as '0', signifies
	we've placed a numeric operand into the provided
	character array */

static int my_index = 0;
static int input_length = 0;
int sign = 1;
char input[MAXINPUT] = {'\0'};
bool end_of_input = false;
bool final_EOF = false;

/* getop takes as input a char [] and returns an int */

int getop(char s[])
{
	/* Check for stack clear */
	if(sig_clear){
		my_index = 0;
	}

	/* main is expecting a newline to signal 'resolve the line'.
	 * after this, it then expects an EOF to break its while loop. */

	/* Check for final EOF. */
	/* This check comes first to prevent repeating end_of_input check */
	if(final_EOF){
		return EOF;
	}
	/* Check for end of input */
	if(end_of_input){
		final_EOF = true;
		return '\n';
	}
	/* Receive input - only if my_index is set to 0. */
	if(my_index == 0){
		memset(input, 0, MAXINPUT);
		input_length = getLine(input, MAXINPUT);
		input[input_length-1]='\0';
	}
	/* Now we have our input; what next? */
	/* Let's process the input for signed values, and replace the sign with a
	 * space */
	for (int i = 0; i < input_length; i++){
		if (input[i] == '-'){
			/* Is this a negation, or a minus? */
			if (input[i+1] != ' ' && input[i+1] != 0){
				sign *= -1; /* the logic to do this is in main() */
				input[i] = '&'; /* replace '-' with our no-op */
			}
		}
	}
	/* Now we've a string of properly signed operands, and operators */
	/* Each time we return something, we need to know where to pick up the next
	 * time main calls getop(). So, we'll need a state tracker variable. See the
	 * static variable 'my_index'. */

	/* Now our logic should be: check for whitespace / tabs, following these
	 * return either an operand or an operator, and advance the my_index to begin
	 * at the *next* position in the array on subsequent calls, unless that
	 * would hit EOF. */

	/* If the input starts with a null terminator, return EOF. */
	/* This is born from debugging. */
	if(input[0]==0 || input[0]=='\n'){
		printf("[*] Terminating: No operators or operands provided.\n");
		return EOF;
	}


	int i = my_index;
	while (input[i] == ' ' || input[i] == '\t'){
		i++; /* skip whitespace or tabs */
		my_index++;
	}
	// Now we need to test for 'is operand' or 'is operator'
	// We've removed all '-' signs which were negations, so no need to worry
	// about that here.
	int c = input[my_index];	/* variable to support tests for operator/operand */
	if(c == 0){
		end_of_input = true;
		return EOF;
	}
	s[1] = '\0'; /* null-terminating */
	if (!isdigit(c) && c != '.'){
		if(input[my_index +1] == 0){
			end_of_input = true;
		}
		my_index++;	/* Advance my_index for next invocation */
		return c;	/* not a number, not a decimal point */
	}
	i = 0; /* reusing our iterator variable */
	if (isdigit(c)){	/* collect integer part */
		int j = i;
		while(isdigit(s[++i] = c = input[my_index+j])){
			j++;
			;
		}
	}
	s[i] = '\0'; /* we need to terminate this */
	if (c == '.'){	/* collect fraction part */
		int j = i;
		while (isdigit(s[++i] = c = input[my_index+j])){
			;
		}
	}
	s[i] = '\0';

	if((my_index+1) < input_length){
		my_index++; /* Advance my_index for next invocation */
	}
	if(input[my_index] == 0){
		end_of_input = true;
	}
	printf("DEBUG: Printing out each value in s:\n");
	for(int x = 0; x < input_length; x++){
		printf("%d: %d\n", x, input[x]);
	}
	return NUMBER;
}
