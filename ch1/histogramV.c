#include <stdio.h>

#define IN 1
#define OUT 0

/* Print a histogram depicting length of various words */

int main(void)
{

/* Required tasks */

/* Probably want a two-dimensional array */
/* of course it'd be great to have dynamic arrays */
/* and while I can do that in C, I'm not yet there */

// Initialize a two-dimensional 15x15 array with ' '

// Upon EOF, print a histogram

	int length = 0;		/* length of current word */
	int lengths[15];	/* array to hold word lengths */
	int v_histogram[15][15];	/* vertical histogram */
	int state = IN;		/* set the flag to TRUE */
	int c;				/* character from getchar */

	/* Zero out the array */
	for (int i = 0; i < 15; ++i){
		lengths[i] = 0;
	}

	/* Zero out the vertical histogram */
	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 15; ++j){
			v_histogram[i][j] = ' ';
		}
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

	/* Let's print it vertically instead */
	/* Stage one is populating it */
	printf("Word length histogram\n");
	for(int i = 0; i < 15; ++i){
		/* Now the vertical magic */
		/* The problem is somewhere in here... */
		for(int j = 0; j < lengths[i]; ++j){
			v_histogram[j][i] = '+';
		}
	}
	/* Stage two is displaying it */
	for(int i = 15; i >= 0; --i){
		for(int j = 0; j < 15; ++j){
			printf("%3c", v_histogram[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 15; ++i){
		printf("%3d", i+1);
	}
	printf("\n");
}
