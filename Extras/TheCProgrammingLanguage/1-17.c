#include <stdio.h>

/*
 * Excercise 1-17 (P. 31)
 * Write a program to print all lines longer than 80 characters
 *
 */

#define	MAXLEN	1000	/* Maximun line length */
#define	LINELEN	80	/* Length to be tested */

int getlines(char line[], int maxline);

int main() {

	int len;
	char lin[MAXLEN];

	while ((len = getlines(lin, MAXLEN)) > 0) if (len > LINELEN) printf("%s", lin);

	putchar('\n');

	return 0;

}

int getlines(char s[], int lim) {

	int c, i;

	for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) s[i] = c;

	if (c == '\n') {
	
		s[i] = c;
		++i;
	
	}

	s[i] = '\0';

	return i;

}
