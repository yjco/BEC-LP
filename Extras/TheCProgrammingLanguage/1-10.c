#include <stdio.h>

/*
 * Exercise 1-10 (P. 10)
 * Replace the input blank to \b, tab to \t and slash to \\
 *
 */

int main() {

	int c;

	while ((c = getchar()) != EOF) {
	
		switch (c) {
		
			case ' ' :
				printf("\\b");
				break;

			case '\t' :
				printf("\\t");
				break;

			case '\\' :
				printf("\\\\");
				break;

			default :
				putchar(c);
		
		}
	
	}

}
