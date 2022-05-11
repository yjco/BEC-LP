#include <stdio.h>
#include <ctype.h>

/*
 * Exercise 5-1 (P. 81)
 * Fix getint() to push '+' and '-' back to the input
 */

int getch(void);
void ungetch(int);

int getint(int *pn);

int main() {

	int i = 666;
	printf("%d\n", getint(&i));

}

int getint(int *pn) {

	int c, d, sign;

	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {

		ungetch(c);
		return c;

	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {

		d = c;

		if (!isdigit(c = getch())) {

			if (c != EOF) ungetch(c);
			ungetch(c);

			return d;

		}

	}

	for (*pn = 0; isdigit(c); c = getch()) *pn = 10 * *pn + (c - '0');
	*pn *= sign;

	if (c != EOF) ungetch(c);

	return c;

}

#define	BUFSIZE	100

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {

	return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch(int c) {

	if (bufp >= BUFSIZE)
		printf("Ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}

