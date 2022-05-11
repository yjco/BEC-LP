#include <stdio.h>

/*
 * Exercise 2-5 (P. 45)
 * Write a program to return the first location of a character in a string that appears in another string
 */

int main() {

	char s1[10] = { 'H', 'L', 'L', 'M', 'T', '\0' };
	char s2[6] = { 'A', 'E', 'I', 'O', 'U', '\0' };

	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {

		for (j = 0; s2[j] != '\0'; j++) if (s1[i] == s2[j]) {

			printf("%d\n", i);
			return 0;

		}

	}

	printf("%d\n", -1);

}
