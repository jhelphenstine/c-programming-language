#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */

int main(void)
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		// lower limit of temp table
	upper = 300;	// upper limit
	step = 20;		// step size

	printf("Fahrenheit\tCelsius\n");
	printf("==========\t=======\n");

	celsius = lower;	
	while (celsius <= upper) {
		// celsius = 5 * (fahr - 32) / 9;
		fahr = ((celsius * 9) / 5) + 32;
		printf("%10.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
