#include <stdio.h>

/*
 * Exercise 1-6 (P. 19)
 * Verify that getchar() != EOF is 0 or 1
 *
 */

int main() {

	int c = getchar() != EOF;
	
	if (c == 0) {
	
		printf("It is 0");
	
	} else if (c == 1) {
	
		printf("It is 1");
	
	}

}
