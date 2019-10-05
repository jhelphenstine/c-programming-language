#include <stdio.h>

#define MAX 120
#define TRUE 1
#define FALSE 0

void strip_line(char line[], int length);


int in_double_quotes = FALSE;
int in_single_quotes = FALSE;
int in_comment = FALSE;

int main(void)
{

	char c;	/* getchar */
	char line[MAX];	/* line of code */
	int i = 0;	/* iterator */
	
	while((c = getchar()) != EOF && i < (MAX-1)){
		if(c == '\n'){
			line[i] = '\0';
			strip_line(line, i+1);
			i = 0;
		}
		else {
			line[i] = c;
			++i;
		}
	}
	if((i + 2) == MAX) {
		printf("ERROR. Line exceeded 120 characters.\n");
	}
	return 0;
}

void strip_line(char line[], int length)
{
	extern int in_double_quotes;
	extern int in_single_quotes;
	extern int in_comment;

	for (int i = 0; i < length; ++i){
		if(line[i] == '\'' && in_single_quotes == FALSE){
			in_single_quotes = TRUE;
		}
		else if (line[i] == '\'' && in_single_quotes == TRUE){
			in_single_quotes = FALSE;
		}
		else if (line[i] == '\"' && in_double_quotes == FALSE) {
			in_double_quotes = TRUE;
		}
		else if (line[i] == '\"' && in_double_quotes == TRUE) {
			in_double_quotes = FALSE;
		}
		if(line[i] == '/' && in_single_quotes == FALSE && in_double_quotes == FALSE){
			if(line[i+1] == '*'){
				in_comment = TRUE;
				i+=2;
			}
		}
		if(line[i] == '*' && in_comment == TRUE){
			if(line[i+1] == '/'){
				in_comment = FALSE;
				i+=2;
			}
		}
		if(in_comment == FALSE){
			putchar(line[i]);
		}
	}
	printf("\n");	/* newline */
	return;
}
