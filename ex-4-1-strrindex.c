#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getLine(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";	/* a pattern to search for */

/* find the rightmost index of a pattern in a string */
int main(void)
{
	char line[MAXLINE];
	int found = 0;
	int match = 0;

	while (getLine(line, MAXLINE) > 0){
		if ((match = strrindex(line, pattern)) >= 0) {
			printf("%s", line);
			found++;
		}
	}
	/* My first time with conditional returns; I like it */
	return (match > 0) ? printf("Match found at offset %d\n", match) : 0;
}

/* getline: get line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;

	i = 0;
	while((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n')){
		s[i++] = c;
	}
	if (c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

/* strrindex: return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k;
	int match = 0;

	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k]!= '\0' && s[j] == t[k]; j++, k++){
			;
		}
		if ((k > 0) && (t[k] == '\0')){
			match = i;
		}
	}	
	/* We move the return out in order to get right-most instance */
	if (match > 0){
		return match;
	}
	return -1;
}
