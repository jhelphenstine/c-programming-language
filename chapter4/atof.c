#include <ctype.h>
#include <stdio.h>
#include <math.h>

/* Code from The C Programming Language - 2nd Edition */
/* By Kernighan and Ritchie, 1987 */
/* With some modifications per Exercise 4-2 instructions */

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power, e;
	int i, sign;
	int e_sign = 1;

	for (i =0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-'){
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.'){
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if ((s[i] == 'e') || (s[i] == 'E')) {
		i++;
	}
	if ((s[i] == '-') || (s[i] == '+')) {
		e_sign = (s[i] == '-') ? -1 : 1; /* Check sign of exponent */
		i++;	/* skip past sign characters */
	}
	for (e = 0.0; isdigit(s[i]); i++){
		e = 10.0 * e + (s[i] - '0');
	}
	e *= e_sign;	/* restore sign to exponent */
	printf("DEBUG: e is: %f\n", e);
	return (sign * val / power) * (pow(10.0, e));
	//	return sign * val / power; /*Old return statement */
}
