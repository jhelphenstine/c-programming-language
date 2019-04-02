#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX 1000
#define WHEEL_OF_FORTUNE "RSTLNE"
#define WHEEL_LENGTH 6

int16_t any(char target[], char source[], int16_t length);

int main(void)
{

	char c;		/* getchar */
	char line[MAX];	/* input line */
	char standard[] = WHEEL_OF_FORTUNE;
	int16_t results = 0;

	int16_t i = 0;	/* iterator */

	while((c = getchar()) != EOF && (i < MAX))
	{
		if(c == '\n')
		{
			line[i] = '\0';
			results = any(line, standard, i);
			if(results > -1)
			{
				printf("Match at position: %d\n", results);
			}
			else
			{
				printf("No match found.\n");
			}
			i = 0;
		}
		else
		{
			line[i++] = c;
		}
	}

	return 0;
}

/* Objective is to report the first hit of any value in a
	pattern string, or -1 if nothing */
int16_t any(char target[], char source[], int16_t length)
{
	int8_t flag = false;
	int16_t k = 0;	/* iterator, but need it after its loop */
	
	for (int16_t i = 0; i < length; ++i)
	{
		for(int16_t j = 0; j < WHEEL_LENGTH; ++j)
		{
			if(target[i] == source[j])
			{
				flag = true;
				return i;
			}
		}
		if(flag == true)
		{
			for(k = i; k < length; ++k)
			{
				target[k] = target[k+1];
			}
			target[k+1] = '\0';
			--i;	/* must decrement iterator as we are 'shifting' */
			--length; /* similarly we are shifting, so overall length decreases */
			flag = false;	/* clear the flag */
		}
	}
	return -1;	/* no match found */
}
