#include <stdio.h>
#include <string.h>

/*
 * Exercise 5-6 (P. 89)
 * Write versions with pointers of all the other programs of the book
 */

void strrev(char *s);

int main() {

	char s[] = "Hello";

	strrev(s);

	printf("%s\n", s);

}

void strrev(char *s) {

	int c;
	char *t;

	for (t = s + (strlen(s) - 1); s < t; s++, t++) {

		c = *s;
		*s = *t;
		*t = c;

	}

}

