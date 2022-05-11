#include <stdio.h>

/*
 * Exercise 1-15 (P. 28)
 * Print a header with the temperature conversion program with a function to convert
 */

float ftoc(float fah);

int main() {

	float fah, step, stop;

	fah = 0;
	step = 10;
	stop = 100;

	printf("Fahrenheit\tCelcius\n");

	while (fah <= stop) {

		printf("%3.0f\t\t%6.1f\n", fah, ftoc(fah));
		fah += step;

	}

}

float ftoc(float fah) {

	return (5 * (fah - 32) / 9);

}
