#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

void itob(int n, char s[], int base);
void reverse(char from[]);
int getValidIntegerInput(char message[], char input[]);

int main(void)
{
	char s[MAX] = {};	/* To hold the converted string */
	char input[MAX] = {};	/* To hold input, necessary for input validation */
	int n;				/* The value to be converted */
	int base = 0;		/* The base for conversion */
	char promptNumber[] = "Number to convert [must be in base 10]: ";
	char promptBase[] = "Base for conversion [2...26]: ";
	
	n = getValidIntegerInput(promptNumber, input);
	while ((base > 26) || (base < 2)){
		base = getValidIntegerInput(promptBase, input);
	}

	printf("Calling function with: %d and %d\n", n, base);
	itob(n, s, base);	/* It's my understanding I'm passing n by value, not reference */
	printf("Converted %d (int) to base %d; result:  %s (string)\n", n, base, s);
	return 0;
}

/* Utility function, because I can't abide seeing this code twice in my program.
	This function accepts a prompt and a character array to store integer input.
	It ensures the user provides integer input. */
int getValidIntegerInput(char message[], char input[])
{
	int valid = FALSE;			/* Part of input checking */
	do {
		printf("%s", message);
		fgets(input, MAX, stdin);	/* Stealing from stackoverflow */
		int len = strlen(input);
		while (len > 0 && isspace(input[len - 1])){
			len--;
		}
		if (len > 0){
			valid = TRUE;
			for (int i = 0; i < len; ++i){
				if (!isdigit(input[i])){
					valid = FALSE;
					break;
				}
			}
		}
	} while (valid == FALSE);
	return atoi(input);
}

/* What began as simple code reuse is complicated by the need to account for
	bases higher than 10, where we'll use A-Z as stand-ins */
void itob(int n, char s[], int b)
{
	long int x = n;	/* this accounts for edge case of minimum value */
	long int sign;
	int i = 0;

	if ((sign = x) < 0)	/* We know it's negative */
		x = -x;	/* We've stored the sign, so flip it */

	do {
		if((x % b) > 10){
			s[i++] = (x % b) + '7'; /* This should start 10 and up at 'A' */
		}
		else {
			s[i++] = (x % b) + '0';	/* Else, start at '0' */
		}
	} while ((x /= b) > 0);

	if (sign < 0){
		s[i++] = '-';	/* Add in the negative sign */
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char from[])
{
	char buffer[strlen(from)-1];	/* temporary storage */

	for(int i = 0; i < strlen(from); ++i){
		buffer[i] = from[(strlen(from)-1)-i]; /* place a reverse into storage */
	}
	for(int i = 0; i < strlen(from); ++i){
		from[i] = buffer[i];				/* overwrite array with its reverse */
	}
}
