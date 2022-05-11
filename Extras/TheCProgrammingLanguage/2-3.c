#include <stdio.h>
#include <ctype.h>
#include <math.h>

/*
 * Exercise 2-3 (P. 43)
 * Write a program to convert hexadecimal digits to integer
 */

int main() {

	char hex[] = { '0', 'x', 'F', '5', 'C', '8' };

	int dec = 0;
	int siz = (int) (sizeof(hex) / sizeof(char)) - 1;

	for (int i = siz; i >= 0; i--) {

		if ((hex[i] == 'x' || hex[i] == 'X')) break;

		if (isdigit(hex[i])) {

			dec += (hex[i] - '0') * (int) pow(16, siz - i);

		} else {

			dec += (tolower(hex[i]) - 87) * (int) pow(16, siz - i);

		}

	}

	printf("%d\n", dec);

}

