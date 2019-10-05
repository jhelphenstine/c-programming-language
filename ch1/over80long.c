#include <stdio.h>

#define MAXLINE 1000
#define MAXTOTAL 100

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
	int len;	/* length of current string */
	int max;	/* longest line length */
	int total_over_80 = 0;	/* Tally of how many lines have more than 80 chars */
	char line[MAXLINE];		/* input line */
	char longest[MAXLINE];	/* longest line currently known */
	char over80[MAXTOTAL][MAXLINE];	/* Collection of lines greater than 80 chars */

	max = 0;	/* initialize to 0; no lines seen */

	/* No line can have a length of 0, so 0 makes a good condition and catches EOF */
	while ((len = my_getline(line, MAXLINE)) > 0){
		if (len > 80){
			copy(over80[total_over_80], line);
			total_over_80++;
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	
	for(int i = 0; i < total_over_80; ++i)
		printf("%s", over80[i]);

	return 0;	/* Successful termination */
}

/* Get a line of input up to a given limit. */
int my_getline(char line[], int limit)
{
	int i, c;

	/* Lines of chars end with a \n */
	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;

	/* But if we had a blank line, we set the array to hold just that */
	if (c == '\n'){
		line[i] = c;	/* If all we got was a newline */
		i++;
	}

	/* This null terminator is useful for finding the end of a line in the array */
	line[i] = '\0';	/* Add a null terminator to each line */
	
	return i;
}

/* Copy until a null terminator is encountered */
void copy(char to[], char from[])
{
	for (int i = 0; i < MAXLINE && (from[i] != '\0'); i++)
		to[i] = from[i];

	return;
}
