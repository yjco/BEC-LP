#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Exercise 7-1 (P. 125)
 * Write a program to convert lowercase to upper and vice versa
 */

int main(int argc, char *argv[]) {

	int c;

	if (strcmp(argv[1], "l")) while ((c = getchar()) != EOF) putchar(toupper(c));
	else if (strcmp(argv[1], "u")) while ((c = getchar()) != EOF) putchar(tolower(c));
	else return 1;

}
