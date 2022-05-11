#include <stdio.h>

/*
 * Exercise 1-16 (P. 31)
 * Fix the longest-line program and remove the line size limit
 */

#define	MAXLINE	1000

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main() {

	int len, max;		/* current length and longest length */
	char line[MAXLINE];	/* current line */
	char longest[MAXLINE];	/* logest line */

	max = 0;

	while ((len = getlines(line, MAXLINE)) > 0) {
	
		if (len > max) {
		
			max = len;
			copy(longest, line);
		
		}

	}

	if (max > 0) printf("%s\n", longest);

	return 0;

}

/* getlines: read line into s[] and return it's length */
int getlines(char s[], int lim) {

	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;

	if (c == '\n') {
	
		s[i] = c;
		++i;

	}

	s[i] = '\0';

	return i;

}

void copy(char to[], char from[]) {

	int i = 0;

	while ((to[i] = from[i]) != '\0') ++i;

	to[i] = '\0';

}
