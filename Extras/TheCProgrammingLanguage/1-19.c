#include <stdio.h>

/*
 * Excercise 1-19 (P. 31)
 * Write a funtion to reverse the input line
 */

#define	MAXLEN	1000	/* Maximum line length */ 

int reverse(char line[]);

int main() {

	int len;

	char line[MAXLEN];

	while (len = reverse(line)) { 
		
		for (; len >= 0; len--) putchar(line[len]); 
		putchar('\n');

	}

}

int reverse(char s[]) {


	int c, i;

	for (i = 0; i < MAXLEN && (c = getchar()) != EOF && c != '\n'; i++) s[i] = c;

	return i - 1;

}
