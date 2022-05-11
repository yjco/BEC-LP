#include <stdio.h>
#include <string.h>

/*
 * Exercise 5-3 (P. 89)
 * Write a pointer version of strcat()
 */

void pstrcat(char *s, char *t);

int main() {

	char s[] = "Hello";
	char t[] = "World";

	pstrcat(s, t);

	printf("%s\n", s);

}

void pstrcat(char *s, char *t) {

	while (*s++ != '\0');
	*s--;
	while (*s++ = *t++);

}
