#include <stdio.h>
#include <string.h>

/*
 * Exercise 5-5 (P. 89)
 * Write versions of strcpy(), strcat() and strcmp() to act on the first n characters
 */

void nstrcpy(char *s, char *t, int n);
void nstrcat(char *s, char *t, int n);
int nstrcmp(char *s, char *t, int n);

int main() {

	char s[] = "Hello";
	char t[] = "World";

	nstrcpy(s, t, 2);
	nstrcat(s, t, 2);
	int n = nstrcmp(s, t, 2);

	printf("%s - %d\n", s, n);

}

void nstrcpy(char *s, char *t, int n) {

	for ( ; n > 0; n--) *s++ = *t++;

}

void nstrcat(char *s, char *t, int n) {

	while (*s++);
	*s--;

	for ( ; n > 0; n--) *s++ = *t++;
	*s = '\0';

}

int nstrcmp(char *s, char *t, int n) {

	for ( ; *s == *t && n > 0; s++, t++, n--) {

		if (*s == '\0') return 0;
		return *s - *t;

	}

}

