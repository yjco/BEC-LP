#include <stdio.h>

/*
 * Exercise 1-13 (P. 23)
 * Write a program to print a histogram of the lengths of the words on the input
 *
 */

int main() {

	int c, l;
	l = 0;

	while ((c = getchar()) != EOF) {
	
		if (c == ' ' || c == '\n' || c == '\t') {
		
			printf(" %d", l);

			l = 0;
			putchar('\n');

		} else {

			l++;
			putchar(c);

		}

	}

}
