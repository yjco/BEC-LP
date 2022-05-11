#include <stdio.h>

/*
 * Excercise 1-12 (P. 23)
 * Write a program to print the input words one per line
 *
 */

int main() {

	int c;

	while ((c = getchar()) != EOF) {
	
		if (c == ' ' || c == '\t') {
		
			putchar('\n');

		} else {
		
			putchar(c);

		}
	
	}

}
