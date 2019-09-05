#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

/* Called by:
	getop()
*/
int getch(void)	/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* Called by:
	getop()
*/
void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE){
		printf("[!] Error: ungetch: too many characters!\n");
	}
	else {
		buf[bufp++] = c;
	}
}

/* ungets(s) -- unget a string.
	WARNING: Author assumes this function is only called from
	main, and that there is a ; at the end of the string.
	If this is not the case, undefined behavior is expected.
*/
/* Called by:
	main()
*/
void ungets(char s[]) /* pushes string back on input */
{
	int iter = 0;		/* iterator */
	while (s[iter] != ';'){
		ungetch(s[iter]);
	}
}
