#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

void itoaWithField(int n, char s[], int field_width_minimum);
void reverse(char from[]);
int getValidIntegerInput(char message[], char input[]);

void itoa(int conv_int, char conv_out[])
{
	//char s[MAX] = {};	/* To hold the converted string */
	//char input[MAX] = {};	/* To hold input, necessary for input validation */
	//int n;				/* The value to be converted */
	int field = 0;		/* The minimum field width */
	//char promptNumber[] = "Number to convert [must be base 10]: ";
	//char promptField[] = "Field width [1...10]: ";
	/* Hasty conversion to utility function
	n = getValidIntegerInput(promptNumber, input);
	while ((field > 10) || (field < 1)){
		field = getValidIntegerInput(promptField, input);
	}
	*/
	//printf("Calling function with: %d and %d\n", n, field);
	itoaWithField(conv_int, conv_out, field);
	//printf("Converted %d (int); result:  %s (string)\n", n, s);
	return;
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

void itoaWithField(int n, char s[], int field_width_minimum)
{
	long int x = n;	/* this accounts for edge case of minimum value */
	long int sign;
	int i = 0;

	if ((sign = x) < 0)	/* We know it's negative */
		x = -x;	/* We've stored the sign, so flip it */

	do {
		s[i++] = (x % 10) + '0';
	} while ((x /= 10) > 0);

	if (sign < 0){
		s[i++] = '-';	/* Add in the negative sign */
	}

	while (i < field_width_minimum){
		s[i++] = ' ';	/* pad with spaces as needed */
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char from[])
{
	char buffer[strlen(from)-1];	/* temporary storage */

	for(int i = 0; i < (int)strlen(from); ++i){
		buffer[i] = from[(strlen(from)-1)-i]; /* place a reverse into storage */
	}
	for(int i = 0; i < (int)strlen(from); ++i){
		from[i] = buffer[i];				/* overwrite array with its reverse */
	}
}
