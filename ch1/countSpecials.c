#include <stdio.h>

int main(void)
{
	int c;
	int t = 0;	/* tabs */
	int nl = 0;	/* newlines */
	int s = 0;	/* space */

	while((c = getchar()) != EOF){
		if(c == '\t')
			++t;
		else if(c == ' ')
			++s;
		else if(c == '\n')
			++nl;
	}
	printf("tabs: %d\n", t);
	printf("newlines: %d\n", nl);
	printf("spaces: %d\n", s);
}

