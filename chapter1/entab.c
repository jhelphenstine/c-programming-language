#include <stdio.h>

#define MAX 1000
#define TAB 8
#define TRUE 1
#define FALSE 0

void entab(char from[], int length);

int main(void)
{
	char line[MAX];			/* input */

	int i = 0;	/* iterator */
	char c;		/* getchar input */

	while((c = getchar()) != EOF && i < (MAX - 1)) {
		if(c == '\n'){
			line[i] = '\0'; /* cap off the string */
			entab(line, i+1);	/* call our entab function */
			i = 0;			/* reset the iterator */
		}
		else {
			line[i] = c;	/* not a newline; build out the array */
			++i;			/* increase the iterator */
		}
	}
	return 0;
}

void entab(char from[], int length)
{
	/* For every grouping of "TAB" printed characters...
		if the end is compiled of spaces, replace THOSE SPACES
		with tabs. ONLY THOSE spaces. */
	/* So, if you find a space, "peek ahead" to the tabstop
		and if it's all spaces until the stop, replace with tab */

	int next_tabstop = 0;	/* current tabstop (set of TAB columns) */
	int spaces_flag = 0;
	
	for(int i = 0; i < length; ++i){	/* iterate over the whole string */
		next_tabstop = ((i + TAB) / TAB) * TAB; /* taking advantage of int division */
		if(from[i] == '\t'){
			putchar('\t');	/* tabs are exceptions; check for them first */
		}
		else if(from[i] == ' '){
			/* Check to make sure we're more than 2 chars from a tab */
			if((i + 1) == next_tabstop){
				putchar(' ');	/* print the space */
			}
			else{
				/* We know we are multiple spaces away */
				for (int j = i; j < (next_tabstop); ++j){
					if(from[j+1] == ' '){
						spaces_flag = TRUE;	/* consecutive spaces */
					}
					else {
						spaces_flag = FALSE; /* not another space */
						putchar(from[j]);
						break;
					}
				}
				if(spaces_flag == TRUE){
					putchar('\t');		/* sum up those spaces with a tab */
					i = next_tabstop-1;	/* arrays are 0-indexed */
					spaces_flag = FALSE;	/* clear the flag */
				}
			}
		}
		else {
			putchar(from[i]);	/* printing non-tab, non-space chars */
		}
	}

	printf("\n");	/* newline */
}
