#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* Part of Exercise 4-3, Part II */
int sign = 1;	/* defining global variable sign */

/* getop: get next operator or numeric operand */
/* Called by:
	main()
*/
int getop(char s[])
{
	int i, c;
	int d = 0;	/* peek-ahead variable */

	/* advance past tabs and whitespace */
	while ((s[0] = c = getch()) == ' ' || c == '\t'){
		;
	}
	/* Exercise 4-3, Part II: Extend calc to handle negative numbers */
	/* check for negative sign by peeking ahead to see if a number follows  */
	if (s[0] == '-') {
		d = getch();
		if ((d != ' ') && (d != '\n')){
			sign *= -1;
			ungetch(d);
			c = '&';	/* '&' represents NOP */
		}
		else {
			ungetch(d);
		}
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.'){
		return c;	/* not a number, not a decimal point */
	}
	i = 0;
	if (isdigit(c)){	/* collect integer part */
		while(isdigit(s[++i] = c = getch())){
			;
		}
	}
	if (c == '.'){	/* collect fraction part */
		while (isdigit(s[++i] = c = getch())){
			;
		}
	}
	s[i] = '\0';
	if (c != EOF){
		ungetch(c);
	}
	return NUMBER;
}
