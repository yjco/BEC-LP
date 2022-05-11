#include <stdio.h>

/*
 * Exercise 2-2 (P. 40)
 * Write a loop equivalent to the following without using && or ||. for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i++)
 */

int main() {

	int i, c, lim;

	i = 0;
	lim = 50;

	while (i < lim - 1) { 
	
		if ((c = getchar()) == '\n') continue;
		if (c == EOF) continue;

		putchar(c);

		i++;

	}

}
