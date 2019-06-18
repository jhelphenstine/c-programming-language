#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

void expand(int min, int max, char output[], int index);

int main(void)
{
	char user_input[MAX];	/* source string */
	char output[MAX];		/* dst string */
	int n = 0;				/* counter */
	char c;					/* input char */

	/* Get the string from the console */
	printf("Please enter a string:\n");
	while((c = getchar()) != EOF && (n < MAX)){
		user_input[n] = c;
		++n;
	}
	user_input[n] = '\0';	/* terminate the string */

	int j = 0;	/* we'll need an index on our output string */
	for (int i = 0; i < strlen(user_input); ++i){
		if(tolower(user_input[i]) == 'a'){
			if(user_input[i+1] == '-'){
				if(tolower(user_input[i+2]) == 'z'){
					expand('a', 'z', output, j); /*invoke expand, a-z*/
					i+=2;	/* iterate ahead past the -z */
					j+=26;	/* advance output index */
				}
				else {
					output[j] = user_input[i];
					j++;
				}
			}
			else {
				output[j] = user_input[i];
				j++;
			}
		}
		else if(user_input[i] == '0'){
			if(user_input[i+1] == '-'){
				if(user_input[i+2] == '9'){
					expand('0', '9', output, j); /* invoke expand, 0-9 */
					i+=2;	/* iterate past the -z */
					j+=10;	/* advance output index */
				}
				else {
					output[j] = user_input[i];
					j++;
				}
			}
			else {
				output[j] = user_input[i];
				j++;
			}
		}
		else {
			output[j] = user_input[i];
			j++;
		}
	}
	output[j] = '\n';

	printf("Output string: \n%s", output);
	return 0;
}

/* We take advantage of chars being ints */
void expand (int min, int max, char output[], int index)
{
	for(int i = min; i <= max; ++i){
		output[index+(i-min)] = i;
	}
	return;
}
