#include <stdio.h>

#define IN 1
#define OUT 0

/* Print a histogram depicting length of various words */

int main(void)
{

/* Required tasks */

// Understand when a word terminates

// Measure the length of the word

// Increment a part of an array with that value

// Upon EOF, print a histogram

	int length = 0;		/* length of current word */
	int lengths[15];	/* array to hold word lengths */
	int state = IN;		/* set the flag to TRUE */
	int c;				/* character from getchar */

	/* Zero out the array */
	for (int i = 0; i < 15; ++i){
		lengths[i] = 0;
	}

	while((c = getchar()) != EOF){

		/* Disregard whitespace characters */
		if(c == ' ' || c == '\n' || c == '\t'){
			state = OUT; /* we are not in a word */
			if(length > 0){
				++lengths[length-1]; /* necessary due to 0 indexing */
			}
			length = 0;
		}
		else {
			state = IN; /* we are in a word now */
			++length;
		}
	}
	/* Now we print the histogram */	
	printf("Word lengths histogram\n");
	for (int i = 0; i < 15; ++i){
		if(lengths[i] == 0)
			continue;
		printf("%2d\t", i+1);
		for(int j = 0; j < lengths[i]; ++j){
			printf("+");
		}
		printf("\n");
	}
}
