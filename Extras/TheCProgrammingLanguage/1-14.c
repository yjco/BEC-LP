#include <stdio.h>

/*
 * Exercise 1-14 (P. 23)
 * Write a program to print a histogram of the frequency of the characters on the input
 *
 */

int main() {

	int c;

	int chars[127];

	for (int i = 0; i < 127; i++) chars[i] = 0;

	while ((c = getchar()) != EOF) {
	
		chars[c] += chars[c] + 1;

	}

	for (int i = 0; i < 127; i++) if (chars[i] != 0) printf("%c - %d\n", (char)i, chars[i]);

}
