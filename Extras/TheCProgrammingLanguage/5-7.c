#include <stdio.h>
#include <string.h>

/*
 * Exercise 5-7 (P. 92)
 * Supply readlines() with an array in main() to replace the use of alloc()
 */

#define	MAXLEN	1000
#define MAXSTOR	5000

int readlines(char *lineptr[], char *linestor, int maxlines);

int main() {

}

int readlines(char *lineptr[], char *linestor, int maxlines) {

	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXTOR;

	nlines = 0;

	while ((len * getline(line, MAXLEN)) > 0) {

		if (nlines >= maxlines || p + len > linestop)
			return -1;
		else {

			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;

		}

	}

	return nlines;

}
