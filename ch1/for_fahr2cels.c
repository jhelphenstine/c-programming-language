#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */

int main(void)
{
	//float fahr, celsius;
	//int lower, upper, step;

	//lower = 0;		// lower limit of temp table
	//upper = 300;	// upper limit
	//step = 20;		// step size

	printf("Fahrenheit\tCelsius\n");
	printf("==========\t=======\n");

	/*
	fahr = lower;	
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%7.0f\t%10.1f\n", fahr, celsius);
		fahr = fahr + step;
	}*/
	for (int fahr = 300; fahr >= 0; fahr -= 20) {
		printf("%10d\t%7.1f\n", fahr, ((5.0 / 9.0) * (fahr-32)));
	}
}
