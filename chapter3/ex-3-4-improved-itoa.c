#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* Declare our prototype. I don't see this on stackoverflow;
	is it no longer idiomatic to do this? */
void itoa(int8_t n, char s[]);
void reverse(char from[]);

int main(void)
{
	char s[5] = {};	/* The max we can have is '-128', plus the trailing 0 */
	int8_t n = -128;
	itoa(n, s);	/* It's my understanding I'm passing n by value, not reference */
	printf("Converted %d (int) to %s (string)\n", n, s);
	return 0;
}

void itoa(int8_t n, char s[])
{
	int16_t x = n;	/* 16 bits allows us to hold the extra sign bit */
	int16_t sign;
	int i = 0;

	if ((sign = x) < 0)	/* We know it's negative */
		x = -x;	/* We've stored the sign, so flip it */

	do {
		s[i++] = (x % 10) + '0';
	} while ((x /= 10) > 0);

	if (sign < 0){
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char from[])
{
	char buffer[strlen(from)-1];	/* temporary storage */

	for(int i = 0; i < strlen(from); ++i){
		buffer[i] = from[(strlen(from)-1)-i]; /* place a reverse into storage */
	}
	for(int i = 0; i < strlen(from); ++i){
		from[i] = buffer[i];				/* overwrite array with its reverse */
	}
}
