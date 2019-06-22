#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* Declare our prototype. I don't see this on stackoverflow;
	is it no longer idiomatic to do this? */
void itoa(int8_t n, char s[]);
void reverse(char from[]);

int main(void)
{
	char s[5] = {};	/* HERE'S THE BLOODY CULPRIT!!! */
	int8_t n = -128;
	printf("[DEBUG]: n is: %d\n", n);	/* this is as expected */
	int8_t o = n;
	printf("[DEBUG]: o is: %d\n", o);	/* so far, so good */
	itoa(n, s);	/* It's my understanding I'm passing n by value, not reference */
	printf("[DEBUG]: n is: %d\n", n);	/* n has changed to 0b110001 */
	printf("[DEBUG]: o is: %d\n", o);	/* o has changed to 0b101101 */
	printf("Converted %d (int) to %s (string)\n", n, s);
	return 0;
}

void itoa(int8_t n, char s[])
{
	int16_t x = n;
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
