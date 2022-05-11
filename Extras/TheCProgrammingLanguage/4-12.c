#include <stdio.h>

/*
 * Exercise 4-12 (P. 74)
 * Write a recursive itoa()
 */

char ritoa(int n);

int main() {

	putchar(ritoa(5874));
	putchar('\n');

}

char ritoa(int n) {

	if (n < 0) {

		putchar('-');
		n = -n;

	}

	if (n / 10) putchar(ritoa(n / 10));
	return (n % 10) + '0';

}

