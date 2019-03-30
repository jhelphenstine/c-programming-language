#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
	int len;	/* length of current string */
	int max;	/* longest line length */
	char line[MAXLINE];		/* input line */
	char longest[MAXLINE];	/* longest line currently known */

	max = 0;	/* initialize to 0; no lines seen */

	/* No line can have a length of 0, so 0 makes a good condition and catches EOF */
	while ((len = my_getline(line, MAXLINE)) > 0){
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		
	}
	if (max > 0){	/* Assuming we got a line, print the longest seen */
		if(longest[sizeof(longest)-1] == '\0')
		printf("%d, %s\n", max, longest);
	}
	return 0;	/* Successful termination */
}

/* Get a line of input up to a given limit. */
int my_getline(char line[], int limit)
{
	int i, c;

	/* Lines of chars end with a \n */
	//for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
		if (i < limit)
			line[i] = c;
	}

	/* But if we had a blank line, we set the array to hold just that */
	if (c == '\n'){
		line[i] = c;	/* If all we got was a newline */
		i++;
	}
	/* This null terminator is useful for finding the end of a line in the array */
	if (i >= limit){
		line[limit-1] = '\0'; /* If we had a line longer than 1000 chars */
	}
	else if (i > 1){
		line[i-1] = '\0';	/* Add a null terminator to each line */
	}
	return i;
}

/* Copy until a null terminator is encountered */
void copy(char to[], char from[])
{
	for (int i = 0; i < MAXLINE && (from[i] != '\0'); ++i)
		to[i] = from[i];

	return;
}
