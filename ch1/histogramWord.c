#include <stdio.h>

/* Print a histogram depicting length of various words */

int main(void)
{

	int letter_freqs[26];		/* Frequency distribution of letters */
	int v_histogram[26][26];	/* vertical histogram */
	int c;				/* character from getchar */
	int max;			/* max freq count */

	/* Zero out the array */
	for (int i = 0; i < 26; ++i){
		letter_freqs[i] = 0;
	}
	/* Zero out the vertical histogram */
	for (int i = 0; i < 26; ++i){
		for (int j = 0; j < 26; ++j){
			v_histogram[i][j] = ' ';
		}
	}

	while((c = getchar()) != EOF){

		/* Disregard whitespace characters */
		if(c == ' ' || c == '\n' || c == '\t'){
			continue;
		}
		else {
			++letter_freqs[c - 'a'];
		}
	}

	/* Stage one is populating it */
	printf("Word length histogram\n\n");
	for(int i = 0; i < 26; ++i){
		/* Now the vertical magic */
		/* The problem is somewhere in here... */
		for(int j = 0; j < letter_freqs[i]; ++j){
			v_histogram[j][i] = '+';
		}
	}
	
	/* Stylistically, I don't want an unnecessarily tall table */
	for (int i = 0; i < 26; ++i){
		if (letter_freqs[i] > max)
			max = letter_freqs[i];
	}

	/* Stage two is displaying it */
	for(int i = max; i >= 0; --i){
		for(int j = 0; j < 26; ++j){
			printf("%3c", v_histogram[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 26; ++i){
		printf("%3c", 'a' + i);
	}
	printf("\n");
}
