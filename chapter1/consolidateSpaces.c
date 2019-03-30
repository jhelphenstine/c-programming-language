#include <stdio.h>

#define TRUE 0
#define FALSE 1

int main(void)
{
	int c;
	int s = FALSE; /* was the last char a space? */

	while((c = getchar()) != EOF){
		if(s == TRUE && c == ' '){
			continue;
		}
		else {
			putchar(c);
			if(c == ' ')
				s = TRUE;
			else
				s = FALSE;
		}
	}
}
