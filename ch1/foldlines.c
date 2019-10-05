/* FUTURE BONUS ROUND: if breaking a word of more than 5 chars,
	rather than newline in front of it, hyphen it */

#include <stdio.h>

#define MARGIN 80	/* margins, because VT100 */
#define MAX	1000	/* max line length */
#define TAB 8
#define TRUE 1
#define FALSE 0

void fold(char line[], int length);
int	count_tabs(char line[], int length);
int detab(char from[], char to[], int length);

int main(void)
{
	char c;			/* for getchar */
	char line[MAX];	/* input line */

	int i = 0;		/* iterator */

	while((c = getchar()) != EOF && i < (MAX - 1)) {
		if(c == '\n'){
			line[i] = '\0';
			fold(line, i+1);
			i = 0;
		}
		else {
			line[i] = c;
			++i;
		}
	}
	if((i + 2) == MAX){
		printf("ERROR. Ingest cap is 1000 chars. Please shorten your input.\n");
		return 0;
	}

	return 0; 

}	

void fold(char line[], int length)
{
	int tabs = count_tabs(line, length);
	char detabbed[(MAX - tabs) + (tabs * 8)];	/* a detabbed version of our line */
	int last_space = 0;	/* last space seen */
	int position = 0;	/* position counter */
	int j = 0;		/* iterator */
	int was_space = FALSE;	/* space flag */

	length = detab(line, detabbed, length);

	for (int i = 0; i < length; ++i){
		putchar(detabbed[i]);
		if(detabbed[i] == ' '){
			was_space = TRUE;
		}
		else {
			was_space = FALSE;
		}
		++position;
		/* The math here allows us to account for multiple 'lines' */
		for(j = (((i/MARGIN) * MARGIN)+i); j < MARGIN * ((i+MARGIN)/MARGIN); ++j){
			if(detabbed[j] == '\n'){
				last_space = 0;		/* we have a hard return before MARGIN */
				position = 0;
				break;
			}
			if(detabbed[j] == ' '){
				last_space = j;
			}
		}
		/* More math to account for multiple lines */
		if (last_space > 0 && j == MARGIN * ((i+MARGIN)/MARGIN)){
			/* we have a space somewhere */
			detabbed[last_space] = '\n';
			last_space = 0;
		}
		if((position+1) % MARGIN == 0){	/* did we reach a margin? */
			if (was_space == FALSE && detabbed[i+1] != ' '){
				putchar('-');			/* put a hyphen if cutting a word */
			}
			putchar('\n');
			while (detabbed[position+1] == ' '){
				++position;
				++i;
			}
			last_space = 0;
			position = 0;
		}

	}
	printf("\n");	/* newline */
}

/* Utility function to count tabs in a string. Knowing this
	helps us set the right size for our detabbed char[] */
int count_tabs(char line[], int length)
{
	int tabs = 0;

	for (int i = 0; i < length; ++i){
		if(line[i] == '\t'){
			++tabs;
		}
	}
	return tabs;
}

/* Rewriting detab to return the length of the new line instead of void.
	All of the putchars now become storing operations */
int detab(char from[], char to[], int length)
{
	int tabwidth = 0;   /* width of any given tab in non_tabs spaces */
    int non_tabs = 0;   /* current number of non_tabs chars within tabstop */
	int k = 0;	/* new iterator for 2nd string */

    for (int i = 0; i < length; ++i){
        if (from[i] != '\t'){ 
            to[k] = from[i];
            ++non_tabs;         /* track non_tabs characters within a tabstop */
            if(non_tabs == TAB){
                non_tabs = 0;   /* non_tabs shouldn't exceed a tabstop */
            }
			++k;
        }
        else if (from[i] == '\t') {     /* we have a tab */
            tabwidth = TAB - non_tabs;  /* calculate actual tab width */
            for (int j = 0; j < tabwidth; ++j){
                to[k+j] = ' ';   /* pad with spaces to the tabstop */
			}
			k += tabwidth;	/* advance the new iterator */
            non_tabs = 0;   /* we have advanced to the next tabstop */
        }
    }
    //printf("\n");   /* newline -- not needed in this implementation */ 
	return k;		/* return the length */
}
