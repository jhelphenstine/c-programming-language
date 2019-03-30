#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "tabs.h"

#define TRUE 1
#define FALSE 0
#define FLAGS 7
#define MAX 120

char flags[FLAGS];	/* state flags */
enum flag{comment,brace,bracket,parentheses,squote,dquote,escape};
/*  0:	comment
	1:	brace
	2:	bracket
	3:	parentheses
	4:	single quote
	5:	double quote
	6:	escape \
*/

void check(char line[], int length, int line_number);
char * strip_line(char line[], int length);
       
int_fast8_t in_double_quotes = FALSE;
int_fast8_t in_single_quotes = FALSE;
int_fast8_t in_comment = FALSE;

int main(void){
	extern char flags[FLAGS];
	char c;	/* getchar */
	char line[MAX];	/* input */
	int_fast8_t i = 0;	/* iterator */
	int16_t num_line = 0;	/* line number */
	
	/* Initialize our flags to FALSE */
	for (int i = 0; i < FLAGS; ++i){
		flags[i] = FALSE;
	}

	while ((c = getchar()) != EOF && i < (MAX -1)){
		if(c == '\n'){
			line[i] = '\0';
			check(line, i, num_line);
			++num_line;
			i = 0;
		}
		else {
			line[i] = c;
			++i;
		}
	}
	
	return 0;
}

void check(char line[], int length, int line_number)
{
	int tabs = count_tabs(line, length);
	char detabbed[(length - tabs)+(tabs * TAB)];
	extern char flags[FLAGS];

	length = detab(line, detabbed, length);
	//strip_line(detabbed, length);
	line = strip_line(detabbed, length);
	

	for (int i = 0; i < length; ++i){
		if(strncmp(&line[i], "{", 1) == 0){
			++flags[1];
		}
		else if(strncmp(&line[i], "[", 1) == 0){
			++flags[2];
		}
		else if(strncmp(&line[i], "(", 1) == 0){
			++flags[3];
		}
		else if(strncmp(&line[i], "\'", 1) == 0){
			++flags[4];
		}
		else if(strncmp(&line[i], "\"", 1) == 0){
			++flags[5];
		}
		else if(strncmp(&line[i], "\\", 1) == 0){
			++flags[6];
			++i;	/* lazy yolo...but when is this not true? */
		}
		else if(strncmp(&line[i], "}", 1) == 0){
			if(flags[1] > 0){
				flags[1]--;
			}
			else {
				printf("Unbalanced brace on line %d\n", line_number);
			}
		}
		else if(strncmp(&line[i],  "]", 1) == 0){
			if(flags[2] > 0){
				flags[2]--;
			}
			else {
				printf("Unbalanced bracket on line %d\n", line_number);
			}
		}
		else if(strncmp(&line[i], ")", 1) == 0){
			if(flags[3] > 0){
				flags[3]--;
			}
			else {
				printf("Unbalanced parentheses on line %d\n", line_number);
			}
		}
		else if(strncmp(&line[i], "\'", 1) == 0){
			if(flags[4] > 0){
				flags[4]--;
			}
			else {
				printf("Unbalanced single quote on line %d\n", line_number);
			}
		}
		else if(strncmp(&line[i], "\"", 1) == 0){
			if(flags[5] > 0){
				flags[5]--;
			}
			else {
				printf("Unbalanced double quote on line %d\n", line_number);
			}
		}


	}
	return;
}


/* Need to refactor this to work on a line rather than simply putchar */
/* This could be so much more efficient if I understood pointers */
char * strip_line(char line[], int length)
{
        extern int_fast8_t in_double_quotes;
        extern int_fast8_t in_single_quotes;
        extern int_fast8_t in_comment;
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
				/* Commenting this out as we refactor this function
                if(line[i] == '*' && in_comment == TRUE){
                        if(line[i+1] == '/'){
                                in_comment = FALSE;
                                i+=2;
                        }
                } */
				/* Begin modification */
				int j = i;
				while(in_comment == TRUE && line[i] != '*'){
					/* What do I want to happen here? */
					line[i] = line[j];
					++j;
				}
				if(line[i] == '*'){
					line[i] = line[i+2];
					i+=2;
					in_comment = FALSE;
				}
				/* Assuming that's ended, I need to "shift down" by "j" */
				
                /* I don't think I need this part now
				if(in_comment == FALSE){
                        putchar(line[i]);
                } */
        }
        //printf("\n");   /* newline */
        return line;
}
