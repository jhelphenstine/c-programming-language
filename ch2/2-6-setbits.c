#include <stdio.h>
#include <stdint.h>

uint16_t setbits(uint16_t x, int16_t p, int16_t n, uint16_t y);

int main(void)
{
	printf("%u\n", setbits(4, 3, 1, 0));


	return 0;
}


/* Write a function setbits(x,p,n,y) that returns x with the n
	bits that begin at position p set to the rightmost n bits
	of y, leaving the other bits unchanged */
uint16_t setbits(uint16_t x, int16_t p, int16_t n, uint16_t y)
{
	/* Step 1, create a mask of the n bits of y */
	/* Step 2, shift it such that it starts at p */
	/* Step 3, bitwise OR with the mask at position p */

	uint16_t mask = ~(~0 << n);
	mask = mask << (p + 1 - n);
	x = x | mask;

	return x;


}
