#include <stdio.h>

/*
 * Exercise 1-18 (P. 31)
 * Write a program to remove trailing spaces and tabs from the input
 */

int main() {

	int c, b;

	b = 0;

	while ((c = getchar()) != EOF) {
	
		if (c == '\t') {
		
			putchar(' ');
			b = 1;

		} else if (c == ' ' && b == 0) {

			putchar(' ');
			b = 1;	
			
		} else if (c == ' ' && b == 1) {

		} else {
		
			putchar(c);
			b = 0;
		
		}
	
	}

	return 0;

}
