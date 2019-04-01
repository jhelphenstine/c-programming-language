#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

#define MAX 200

int32_t htoi(char target[], int16_t length);

int main(void)
{
	char c;		/* input */
	char s[MAX];	/* input array */
	int16_t i = 0;	/* iterator */
	int32_t int_version = 0;	/* output */

	while(((c = getchar()) != EOF) && (i < MAX))
	{
		if(c == '\n')
		{
			s[i] = '\0';
			int_version = htoi(s, i);
			i = 0;	/* reset iterator */
		}
		else {
			s[i++] = (char) tolower(c);
		}
	}
	
	printf("Converted hexadecimal characters to integer value: %d\n", int_version);
	return 0;
}

/* We will ignore values outside of 0-9, a-f, A-F, but tolerate leading 0x || 0X */
int32_t htoi(char target[], int16_t length)
{

	int32_t converted = 0;	/* this is our return value */	
	int16_t converted_length = 0;	/* this is our true convered length */

	/* What's the formula for determining positional value? */
	/* First we need to clean the data */
	int16_t clean[length];
	int16_t j;

	for(int16_t i = j = 0; i < length; ++i)
	{
		if(target[i] == '0')
		{
			if(target[i+1] == 'x')
			{
				i++;
			}
			else
			{
				clean[j] = 0;
				++converted_length;
				++j;
			}
		}
		else if(target[i] >= 'a' && target[i] <= 'f')
		{
			switch(target[i])
			{
				case 'a':
				{
					clean[j] = 10;
					++converted_length;
					++j;
					break;
				}
				case 'b':
				{
					clean[j] = 11;
					++converted_length;
					++j;
					break;
				}
				case 'c':
				{
					clean[j] = 12;
					++converted_length;
					++j;
					break;
				}
				case 'd':
				{
					clean[j] = 13;
					++converted_length;
					++j;
					break;
				}
				case 'e':
				{
					clean[j] = 14;
					++converted_length;
					++j;
					break;
				}
				case 'f':
				{
					clean[j] = 15;
					++converted_length;
					++j;
					break;
				}
			}
		}
		else if(target[i] > '0' && target[i] < '9')
		{
			clean[j] = target[i] - '0';
			++converted_length;
			++j;
		}
	}

	for(int8_t j = 0; j < converted_length; ++j)
	{
		/* We'll assume little endian */
		converted += (pow(16, converted_length-j-1) * clean[j]);
	}
	
	return converted;	/* done here */
}
