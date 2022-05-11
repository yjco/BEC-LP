#include <stdio.h>
#include <string.h>

/*
 * Exercise 5-13 (P. 98)
 * Write a program to print the last n lines of a input where n = 10 by default
 */

#define	NLINES	10
int nlines = NLINES;

int main(int argc, char *argv[]) {

	int c;

	if (argc > 1) {

		while (c = *++argv[1]) { 
			
			switch (c) {

				case 'n' :

					nlines = 0;
					int i = -1, j = 1;

					while (argv[2][++i] == '0');
		
					for (i = strlen(argv[2]) - 1; i >= 0; i--, j *= 10)
						nlines = (argv[2][i] - '0' == 0) ? nlines * 10 : nlines + (argv[2][i] - '0') * j;

					break;

				default :

					printf("Unknown option -%c\n", c);
					return -1;

			}

		}

	}

	while ((c = getchar()) != EOF && nlines > 0) {

		if (c == '\n') nlines--;
		putchar(c);

	}

}

