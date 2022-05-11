#include <stdio.h>

/*
 * Exercise 2-7 (P. 46)
 * Invert n bits from x beggining in p
 */

unsigned invert(x, p, n) {

	return  (((~0 << (p + 1)) | ~(~0 << (p + 1 - n))) ^ x);

}

int main() {

	printf("%d/n", invert(60, 4, 3));

}
