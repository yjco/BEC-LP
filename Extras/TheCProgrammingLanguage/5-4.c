#include <stdio.h>
#include <string.h>

/*
 * Exercise 5-4 (P. 89)
 * Write strend() which returns 1 if t is in the end of s
 */

int pstrend(char *s, char *t);

int main() {

	char s[] = "Hello";
	char t[] = "llo";

	printf("%d\n", pstrend(s, t));

}

int pstrend(char *s, char *t) {

	int i = 0;
	while (*t++ != '\0') i++;
	while (*s++ != '\0');

	*--t;
	*--s;

	for (; i > 0; i--) {

		if (*s-- != *t--) return 0;

	}

	return 1;

}
