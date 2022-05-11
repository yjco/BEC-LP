#include <stdio.h>

/*
 * Exercise 1-5 (P. 17)
 * Write a inverted version of the temperature conversion program
 */

int main() {

	printf("Fahrenheit\tCelcius\n");

	for (int fah = 100; fah >= 0; fah -= 10) printf("%3d\t\t%6.1f\n", fah, ((5.0 * (fah - 32)) / 9.0));

}
