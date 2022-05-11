#include <stdio.h>
#include <string.h>

/*
 * Exercise 3-4 (P. 56)
 * Convert n into a base b number to s
 */

void itob(int n, char s[], int b);

int main() {

	int n = 28;
	char s[2];

	itob(n, s, 16);

	printf("%s\n", s);

}

void itob(int n, char s[], int b) {

	int i, j, sign;
	i = 0;
	
	if ((sign = n) < 0) n = -n;
	
	do {

		j = n % b;
		s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;

	} while((n /= b) > 0);

	if (sign < 0) s[i++] = '-';
	
	strrev(s);

	s[i] = '\0';

}
