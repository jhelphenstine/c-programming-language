#include <stdio.h>

int main(void)
{
	int c;
	
	while ((c = getchar()) != EOF){
		putchar(c);
	//	printf("getchar() != EOF currently evaluates to: %d\n", c != EOF);
	}
	//printf("getchar() != EOF evaluated as %d, terminating\n", c != EOF);
}
