/* Convert escaped characters into visual form, such as \n and \t */
#include <stdio.h>
#define MAX 10000

void convert(char s[], char t[], int length);


void main()
{
	char s[MAX];	/* declare our buffer */
	char t[MAX];	/* and a destination */
	int n = 0;		/* declare a counter */
	char c;			/* our character catcher */

	while(((c = getchar()) != EOF) && (n < MAX)){
		s[n] = c;
		++n;
	}

	convert(s, t, n);
	printf("Converted string:\n");
	printf("%s\n", t);
	return;
}

void convert(char s[], char t[], int length)
{

	int j = 0; //Whatever, it works
	for(int i; i < length; ++i){
		switch(s[i]) {
			case('\t'):
				t[j] = '\\';
				t[j+1] = 't';
				j+=2;
				break;
			case('\n'):
				t[j] = '\\';
				t[j+1] = 'n';
				j+=2;
				break;
			default:
				t[j] = s[i];
				++j;
				break;
		}
	}
}
