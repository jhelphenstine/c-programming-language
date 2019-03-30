#include <stdio.h>

int main(void)
{
	long nc;	// Number of characters copied

	nc = 0;
	while (getchar() != EOF)
		++nc;	// We'll discuss prefix vs postfix in ch2
	printf("%ld\n", nc);
}
