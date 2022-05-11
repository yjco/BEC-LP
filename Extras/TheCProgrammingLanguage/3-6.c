#include <stdio.h>
#include <string.h>

/*
 * Exercise 3-6 (P. 57)
 * Make a version of itoa() which receives an argument to define minimum field width
 */

#define	abs(x)	((x) < 0 ? -(x) : (x))

void itoa(int n, char *s[], int w);

int main() {

	int n = 28;
	char s[2];

	itoa(n, s);

	printf("%s\n", s);

}

void itoa(int n, char s[], int w) {

	int i, sign;

	sign = n;
	i = 0;

	do {

		s[i++] = abs(n % 10) + '0';

	} while((n /= 10) != 0);

	if (sign < 0) s[i++] = '-';
		
	w = w - strlen(s);

	for (w = w - strlen(s); w > 0; w--) s[i++] = ' ';

	strrev(s);

	s[i] = '\0';
		
}
