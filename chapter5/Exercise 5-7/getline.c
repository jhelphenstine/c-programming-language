/* getline: get line into s, return length */
#include <stdio.h>
#include <string.h>	/* for strlen */

#define MAX 100

/* getline: get line into s, return length */
/* this version uses pointers instead of array indices */
int getline_p(char *s, int lim)
{
	int c;
	char *p;

	p = s;
	while((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n')){
		*p++ = c;
	}
	if (c == '\n'){
		*p++ = c;
	}
	*p = '\0';
	return strlen(s);
}