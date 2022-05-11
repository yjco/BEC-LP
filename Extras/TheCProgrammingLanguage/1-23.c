#include <stdio.h>
#include <stdbool.h>

/*
 * Exercise 1-23 (P. 34)
 * Write a program to remove C comments
 */

int main() {

	int c;
	bool quote, state;

	state = quote = false;

	while ((c = getchar()) != EOF) {

		if (c == '\"' || c == '\'') quote = !quote;

		if (c == '/' && !quote) { 
			
			state = !state;
			continue;

		}

		if (state) continue;

		putchar(c);

	}

}

