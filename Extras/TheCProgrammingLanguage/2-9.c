#include <stdio.h>

/*
 * Exercise 2-9 (P. 47)
 * Explain why does x &= (x - 1) removes the last 1 bit from x and write a faster bitcount()
 */

int bitcount(unsigned x) {

	int b;

	for (b = 0; x != 0; x &= x - 1) b++;
	
	return b;

}

int main() {

	printf("%d\n", bitcount(60));

}
