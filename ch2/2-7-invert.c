#include <stdio.h>
#include <stdint.h>

uint8_t invert(uint8_t x, int8_t p, int8_t n);

int main(void)
{
	uint8_t x = 128;	/* test value for x */
	int8_t p = 7;	/* corresponds to 128 */
	/* inverting only 2 bit should yield 64 */
	int8_t n = 2;

	printf("%u\n", invert(x, p, n));



	return 0;
}

/* Write a function invert(x, p, n) that returns x with the
	n bits beginning at position p inverted, leaving the others
	unchanged */
uint8_t invert(uint8_t x, int8_t p, int8_t n)
{
	

	return 0;
}
