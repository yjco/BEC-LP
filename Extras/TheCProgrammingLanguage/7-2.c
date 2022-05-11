#include <stdio.h>

/*
 * Exercise 7-2 (P. 127)
 * Write a program to print arbitrary input in a sensible way
 */

int main() {

	int c, i;
	char buffer[1000];

	i = 0;

	while ((c = getchar()) != EOF) {

		buffer[i++] = c;

		if (i == 1000) break;

	}

	for (int j = 0; j < i; j++) {

		if (j % 10 == 0) putchar('\n');
		if (buffer[j] == '\n') continue;
		putchar(buffer[j]);

	}

}

