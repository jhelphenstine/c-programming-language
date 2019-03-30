#include <stdio.h>

int main(void)
{
	/* count lines of input */
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("\n%d\n", nl); /* The first \n serves to clear the D from EOF ^D */
}
