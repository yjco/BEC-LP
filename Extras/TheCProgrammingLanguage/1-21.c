#include <stdio.h>

/*
 * Exercise 1-21 (P. 34)
 * Write a program to replace spaces with tabs
 */

#define	SPACETAB	8

int main() {

	int i, j, c, b, tabs, spcs;

	b = 0;

	while (1 == 1) {

		for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
			
			if (c == ' ') {
			
				b++;
			
			} else if (c != ' ' && b != 0) {

				tabs = b / SPACETAB;

				if (tabs == 0) spcs = b;
				else spcs = b - (SPACETAB * tabs - (i - b));

				for (j = 0; j < tabs; j++) putchar('\t');
				for (j = 0; j < spcs; j++) putchar(' ');

				i = 0;
				b = 0;

				putchar(c);
			
			} else {
			
				putchar(c);
			
			}

		}

		putchar('\n');

		printf("T:%d S:%d\n", tabs, spcs);

	}

}
