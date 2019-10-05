#include <stdio.h>
#include <stdint.h> /* Need to get used to modern C */

int main(void)
{
	/* Exercise is to replace this loop without using || or && :
		for (i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
			s[i] = c;
	*/
	int8_t i;
	char c;
	char s[20];
	int_fast8_t lim = 20;

	while((c = getchar()) != EOF){
		if(c == '\n'){
			break;
		}
		else if(i < lim-1){
			s[i] = c;
		}
		else {
			break;
		}
		++lim;
	}
	return 0;
}
