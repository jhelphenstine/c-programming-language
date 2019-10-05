#include <stdio.h>

int main(void)
{
	short s = 0;
	int i = 0;
	long l = 0;
	float f = 0.0;
	double d = 0;
	long double ld = 0;

	printf("A short uses %d bits\n", (1 << sizeof(s)));
	printf("An integer uses %d bits\n", (1 << sizeof(i)));
	printf("A long uses %d bits\n", (1 << sizeof(l)));
	printf("A float uses %d bits\n", (1 << sizeof(f)));
	printf("A double uses %d bits\n", (1 << sizeof(d)));
	printf("A long double uses %d bits\n", (1 << sizeof(ld)));
}
