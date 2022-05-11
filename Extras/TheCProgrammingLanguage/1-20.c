#include <stdio.h>

/*
 * Exercise 1-20 (P. 34)
 * Write a program to replace tab with spaces
 */

#define	SPACETAB	8	/* Tab column length */

int main() {

	int c, j, i;

	while (1 == 1) {
	
		for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
	
			if (c == '\t') {
		
				for (j = 0; j < SPACETAB - (i % SPACETAB); j++) putchar(' ');
				i += j - 1;

			} else {

				putchar(c);

			}
	
		}

		putchar('\n');

	}

}
