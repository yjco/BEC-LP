#include <stdio.h>

/*
 * Exercise 4-1 (P. 61)
 * Re-write strindex() which returns the righmost match
 */

int strindex(char string[], char pattern[]);

int main() {

	printf("%d\n", strindex("Could the ould be loulder", "ould"));

}

int strindex(char s[], char p[]) {

	int i, j, k;

	s = strrev(s);
	p = strrev(p);

	for (i = 0; s[i] != '\0'; i++) {

		for (j = i, k = 0; p[k] != '\0' && s[j] == p[k]; j++, k++);
		if (k > 0 && p[k] == '\0') return i;

	}

	return -1;

}