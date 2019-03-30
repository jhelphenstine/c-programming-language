#include <stdio.h>

#define MAX 1000
#define TAB 8

void detab(char from[], int length);

int main(void)
{
	char line[MAX];			/* input */

	int i = 0;	/* iterator */
	char c;		/* getchar input */

	while((c = getchar()) != EOF && i < (MAX - 1)) {
		if(c == '\n'){
			line[i] = '\0'; /* cap off the string */
			detab(line, i+1);	/* call our detab function */
			i = 0;			/* reset the iterator */
		}
		else {
			line[i] = c;	/* not a newline; build out the array */
			++i;			/* increase the iterator */
		}
	}
	return 0;
}

void detab(char from[], int length)
{
	int tabwidth = 0;	/* width of any given tab in non_tabs spaces */
	int non_tabs = 0;	/* current number of non_tabs chars within tabstop */
	
	for (int i = 0; i < length; ++i){
		if (from[i] != '\t') {
			putchar(from[i]);
			++non_tabs;			/* track non_tabs characters within a tabstop */
			if(non_tabs == TAB){
				non_tabs = 0;	/* non_tabs shouldn't exceed a tabstop */
			}
		}
		else if (from[i] == '\t') {		/* we have a tab */
			tabwidth = TAB - non_tabs;	/* calculate actual tab width */
			for (int j = 0; j < tabwidth; ++j){
				putchar(' ');	/* pad with spaces to the tabstop */
			}
			non_tabs = 0;	/* we have advanced to the next tabstop */
		}
	}
	printf("\n");	/* newline */
}
