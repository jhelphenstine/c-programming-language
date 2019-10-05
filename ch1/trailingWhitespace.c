#include <stdio.h>
#include <string.h>

#define MAX 1000

int main(void)
{
	int i = 0;		/* Placeholder */
	char c;			/* Current getchar */
	char line[MAX];	/* Line for holding input */

	while ((c = getchar()) != EOF){
		line[i] = c;
		++i;
	}
	if (line[0] == '\n'){
		printf("Blank lines are subject to deletion!\n");
	}
	else {
		printf("%lu\n", strlen(line));
		for (int j = strlen(line); j > 0; --j){
			if ((line[j] == ' ') || (line[j] == '\t')){
				line[j] = '\0';
				printf("DEBUG: Made a replacement!\n");
			}
			else {
				break;
			}
		}
		char adjusted[strlen(line)];
		for (int i = 0; line[i] != '\0'; ++i){
			adjusted[i] = line[i];
		}	

		printf("%lu\n", strlen(adjusted));
		printf("%s\n", adjusted);
	}
	
	return 0;
}
