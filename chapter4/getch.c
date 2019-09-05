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
