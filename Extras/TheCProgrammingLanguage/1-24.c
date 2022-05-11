#include <stdio.h>

/*
 * Exercise 1-24 (P. 34)
 * Write a program to verify unmatched braces
 */

int main() {

	int i, c, b;

	while ((c = getchar()) != EOF) {

		if (c == '{') b++;
		else if (c == '}') b--;

	}

	if (b != 0) printf("Check for the braces!\n");

}

