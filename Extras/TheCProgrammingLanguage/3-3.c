#include <stdio.h>
#include <string.h>

/*
 * Exercise 3-3 (P. 56)
 * Write a function to replace expand shortand - into a complete list
 */

void expand(char s1[], char s2[]);

int main() {

	char st1[] = { 'a', '-', 'z', '0', '-', '9', '\0' };
	char st2[100];

	expand(st1, st2);

	printf("%s\n", st2);	

}

void expand(char s1[], char s2[]) {

	char c;
	int i, j;

	i = j = 0;

	while ((c = s1[i++]) != '\0') {

		if (s1[i] == '-' && s1[i + 1] >= c) {

			i++;

			while (c < s1[i])
				s2[j++] = c++;

		} else
			s2[j++] = c;

	}

	s2[j] = '\0';

}
