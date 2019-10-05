#include <stdio.h>
#include <string.h>

#define MAX 1000

void reverse(char from[]);

int main(void)
{
	char line[MAX];			/* input */

	int i = 0;	/* iterator */
	char c;		/* getchar input */

	while((c = getchar()) != EOF && i < (MAX - 1)) {
		if(c == '\n'){
			line[i] = '\0'; /* cap off the string */
			reverse(line);	/* call our reverse function */
			printf("%s\n", line); /* experiment, change from 'reverse_line' */
			i = 0;			/* reset the iterator */
		}
		else {
			line[i] = c;	/* not a newline; build out the array */
			++i;			/* increase the iterator */
		}
	}
	return 0;
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

