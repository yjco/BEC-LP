#include <stdio.h>
#include <ctype.h>

/*
 * Exercise 5-2 (P. 81)
 * Write a float version of getint()
 */

int getch(void);
void ungetch(int);

int getfloat(float *pn);

int main() {

	float i = 66.6;
	printf("%d\n", getfloat(&i));

}

int getfloat(float *pn) {

	int c, sign;
	float power;

	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {

		ungetch(c);
		return c;

	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') c getch();

	for (*pn = 0.0; isdigit(c); c = getch()) *pn = 10.0 * *pn + (c - '0');

	if (c == '.') c = getch();

	for (power = 1.0; isdigit(c); c = getch()) {

		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;

	}

	*pn *= sign / power;

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

