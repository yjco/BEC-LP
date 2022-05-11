#include <stdio.h>

/*
 * Exercise 1-9 (P. 21)
 * Write a program to replace all blanks with a single blank
 *
 */

int main() {

	int c, b;

	b = 0;

	while ((c = getchar()) != EOF) {

		if (c == ' ') {
		
			if (!b) {
			
				b = 1;
				putchar(c);

			}
		
		} else {
		
			b = 0;
			putchar(c);
		
		}
	
	}

}
