#include <stdio.h>

/*
 * Exercise 1-22 (P. 34)
 * Write a program to break a long line into more lines
 */

#define	LINELENGTH	30

int main() {

	int i, c;

	while (1 == 1) {

		for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {

			if (i > LINELENGTH && (c == ' ' || c == '\t')) {

				putchar('\n');

				i = 0;
	
			} else {

				putchar(c);

			}

		}

		putchar('\n');

	}

}

