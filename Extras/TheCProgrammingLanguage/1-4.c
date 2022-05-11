#include <stdio.h>

/*
 * Exercise 1-4 (P. 15)
 * Write a Celcius to Fahrenheit program
 */

int main() {

	float cel, fah, step, stop;

	cel = 0;
	step = 10;
	stop = 100;

	printf("Celcius\t\tFahrenheit\n");

	while (cel <= stop) {

		fah = ((cel * 9) / 5) + 32;

		printf("%3.0f\t\t%6.1f\n", cel, fah);
		cel += step;

	}

}
