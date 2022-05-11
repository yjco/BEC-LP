#include <stdio.h>
#include <ctype.h>

/*
 * Exercise 6-1 (P. 111) 
 * Write a version of getword() that handles underscores and other string canstants 
 */

#define	MAXWORD	100

int getword(char *word, int lim);
int getch();
void ungetch(int c);

int main() {

	char word[MAXWORD];

	printf("%s\n", getword(word, MAXWORD));

}

int getword(char *word, int lim) {

	int c, getch(void);
	void ungetch(int);
	char *w = word; 

	while (isspace(c = getch()));

	if (c != EOF) *w++ = c;

	if (!isalpha(c)) {

		*w = '\0';
		return c;

	}

	for ( ; --lim > 0; w++) {

		if (!isalnum(*w = getch())) {

			ungetch(*w);
			break;

		}

	}

	*w = '\0';
	return word[0];

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

