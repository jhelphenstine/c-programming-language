#include <stdio.h>
#include <string.h> // for memset
#include <ctype.h>
#include "calc.h"

#define MAXINPUT 100 /* that's all we'll allow */

/* getop: return a numeric operand or operator */
/* from calc.h: NUMBER is defined as '0', signifies
	we've placed a numeric operand into the provided
	character array */
/* Called by:
	main.c - main()
	*/

static int my_index = 0;
static int input_length = 0;
int sign = 1;
char input[MAXINPUT] = {'\0'};

/* getop takes as input a char [] and returns an int */

int getop(char s[])
{
	/* Check for stack clear */
	if(sig_stack_cleared){
		my_index = 0;
		sign = 1;
		sig_stack_cleared = false;
	}

	/* Receive input - only if my_index is set to 0. */
	if(my_index == 0){
		memset(input, '\0', MAXINPUT);
		input_length = getLine(input, MAXINPUT);
	}
	/* Now we have our input; what next? */
	/* Let's process the input for signed values, and replace the sign with a
	 * no-op */
	for (int i = 0; i < input_length; i++){
		if (input[i] == '-'){
			/* Is this a negation, or a minus? */
			if (isdigit(input[i+1])){
				sign *= -1; /* the logic to do this is in main() */
				input[i] = '&'; /* replace '-' with our no-op */
			}
		}
	}

	while ((s[0] = input[my_index]) == ' ' || input[my_index] == '\t'){
		my_index++; /* skip whitespace or tabs */
	}

	// Now we need to test for 'is operand' or 'is operator'
	int c = input[my_index];	/* convenience variable for testing */
	if (!isdigit(c) && c != '.'){
		my_index++;	/* Advance my_index for next invocation */
		s[1] = '\0'; /* null-terminate before we return */
		return c;	/* not a number, not a decimal point */
	}
	int i = 0;
	if (isdigit(c)){	/* collect integer part */
		while(isdigit(s[i++] = c = input[my_index])){
			my_index++;
			;
		}
	}
	if (c == '.'){	/* collect fraction part */
		my_index++;
		while (isdigit(s[i++] = c = input[my_index])){
			my_index++;
		}
	}
	if((my_index+1) < input_length){
		my_index++; /* Advance my_index for next invocation */
	}
	s[i] = '\0'; /* let's cap off s with a null terminator */
	return NUMBER;
}
