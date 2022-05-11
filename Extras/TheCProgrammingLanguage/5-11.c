#include <stdio.h>
#include <string.h>

/*
 * Exercise 5-10 (P. 98)
 * Rewrite entab() and detab() to accept and argument to define tab size
 */

int SPACETAB = 8;

void entab();
void detab();

int main(int argc, char *argv[]) {

	if (argc > 1) { 

		SPACETAB = 0;
		int i = -1, j = 1;

		while (argv[1][++i] == '0');
		
		for (i = strlen(argv[1]) - 1; i >= 0; i--, j *= 10)
			SPACETAB = (argv[1][i] - '0' == 0) ? SPACETAB * 10 : SPACETAB + (argv[1][i] - '0') * j;

	}

	printf("%d\n", SPACETAB);

}

void entab() {

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

void detab() {

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

