#include <stdio.h>
#include <stdint.h>

#define MAX 1000
#define WHEEL_OF_FORTUNE "RSTLNE"
#define WHEEL_LENGTH 6

void squeeze(char target[], char source[], int16_t length);

int main(void)
{

	char c;		/* getchar */
	char line[MAX];	/* input line */
	char standard[] = WHEEL_OF_FORTUNE;

	int16_t i = 0;	/* iterator */

	while((c = getchar()) != EOF && (i < MAX))
	{
		if(c == '\n')
		{
			line[i] = '\0';
			squeeze(line, standard, i);
			printf("Squeezed line: %s\n", line);
			i = 0;
		}
		else
		{
			line[i++] = c;
		}
	}

	return 0;
}

/* Objective is to strip all chars from our source string which
	match on members of a second string. As this is just an exercise,
	I'm going to have a hard-coded 2nd string (see the #define) */
void squeeze(char target[], char source[], int16_t length)
{
	int8_t flag = 0;
	int16_t j = 0;	/* iterator */
	int16_t k = 0;	/* second iterator */
	
	for (int16_t i = 0; i < length; ++i)
	{
		for(j = 0; j < WHEEL_LENGTH; ++j)
		{
			if(target[i] == source[j])
			{
				flag = 1;
			}
		}
		if(flag == 1)
		{
			for(k = i; k < length; ++k)
			{
				target[k] = target[k+1];
			}
			target[k+1] = '\0';
			--i;	/* must decrement iterator as we are 'shifting' */
			--length; /* similarly we are shifting, so overall length decreases */
			flag = 0;	/* clear the flag */
		}
	}
	return;
}
