#include <stdio.h>

/*
 * Exercise 2-4 (P. 44)
 * Write a program to delete any character present in one string from another string
 */

int main() {

	char s1[10] = { 'H', 'E', 'L', 'L', 'O', 'M', 'O', 'T', 'O', '\0' };
	char s2[6] = { 'A', 'E', 'I', 'O', 'U', '\0' };

	int i, j, b;

	for (i = 0; s1[i] != '\0'; i++) {

		for (j = 0; s2[j] != '\0'; j++) if (s1[i] == s2[j]) b = 1;

		if (b == 1) {
		
			b = 0;	
			continue;

		}
		
		putchar(s1[i]);

	}

	putchar('\n');

}
