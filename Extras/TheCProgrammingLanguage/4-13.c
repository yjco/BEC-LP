#include <stdio.h>
#include <string.h>

/*
 * Exercise 4-13 (P. 74)
 * Write a recursive strrev(char[])
 */

void rstrrev(char s[], int i, int len);

int main() {
	
	char s[] = "THE ALGORITHM";
	rstrrev(s, 0, strlen(s));

	printf("%s\n", s);

}

void rstrrev(char s[], int i, int len) {

	int c, j;

	j = len - (i + 1);

	if (i < j) {

		c = s[i];
		s[i] = s[j];
		s[j] = c;

		rstrrev(s, ++i, len);

	}

}

