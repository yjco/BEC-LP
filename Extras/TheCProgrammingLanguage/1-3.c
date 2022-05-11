#include <stdio.h>

/*
 * Exercise 1-3 (P. 15)
 * Print a header with the temperature conversion program
 */

int main() {

	float cel, fah, step, stop;

	fah = 0;
	step = 10;
	stop = 100;

	printf("Fahrenheit\tCelcius\n");

	while (fah <= stop) {

		cel = (5 * (fah - 32) / 9);

		printf("%3.0f\t\t%6.1f\n", fah, cel);
		fah += step;

	}

}
