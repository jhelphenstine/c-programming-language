#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

void expand(char s1[], char s2[]);

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

	expand(user_input, output);

	printf("Output string is: %s\n", output);
	return 0;
}

/* Function to expand a-z and 0-9 */
void expand(char s1[], char s2[])
{
	int s1_index = 0;
	int s2_index = 0;
	for(s1_index; s1_index < strlen(s1); s1_index++)
	{
		switch(tolower(s1[s1_index])) {
			case 'a':
				if((s1[s1_index+1] == '-') && \
					(tolower(s1[s1_index+2]) == 'z')) {
					for(int i = s1[s1_index]; i <= s1[s1_index+2]; ++i){
						s2[s2_index + (i-s1[s1_index])] = i;
					}
					s1_index += 2;
					s2_index += 26;
					break;
				}
				else {
					s2[s2_index] = s1[s1_index];
					s2_index++;
					break;
				}
			case '0':
				if((s1[s1_index+1] == '-') && \
					(s1[s1_index+2] == '9')) {
					for(int i = s1[s1_index]; i <= s1[s1_index+2]; ++i){
						s2[s2_index + (i-s1[s1_index])] = i;
					}
					s1_index += 2;
					s2_index += 10;
					break;
				}
				else {
					s2[s2_index] = s1[s1_index];
					s2_index++;
					break;
				}
			default:
				s2[s2_index] = s1[s1_index];
				s2_index++;
				break;
		}
	}
	s2[s2_index] = '\0';	/* need to null-terminate s2 */
	return;
}
