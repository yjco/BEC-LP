#include <stdio.h>
#include <string.h>

/*
 * Exercise 3-4 (P. 56)
 * Explain why the largest negative number can be used in the itoa() and fix it to work
 */

#define	abs(x)	((x) < 0 ? -(x) : (x))

void itoa(int n, char *s[]);

int main() {

	int n = 28;
	char s[2];

	itoa(n, s);

	printf("%s\n", s);

}

void itoa(int n, char s[]) {

	int i, sign;

	sign = n;
	i = 0;

	do {

		s[i++] = abs(n % 10) + '0';

	} while((n /= 10) != 0);

	if (sign < 0) s[i++] = '-';

	strrev(s);

	s[i] = '\0';
		
}
