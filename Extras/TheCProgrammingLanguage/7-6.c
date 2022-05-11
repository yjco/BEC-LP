#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Exercise 7-6 (P. 135)
 * Write a program to print the different lines from 2 files
 */

int main(int argc, char *argv[]) {

	if (argc < 3) {
	
		printf("Error: you must specify 2 files!\n");	
		exit(1);

	}

	FILE *one = fopen(argv[1], "r");
	FILE *two = fopen(argv[2], "r");

	int c, d;

	int i, j;
	i = j = 0;

	char cbuff[100];
	char dbuff[100];

	while ((c = getc(one)) != EOF && (d = getc(two)) != EOF) {

		if (c == '\n' || d == '\n') {

			cbuff[i] = '\0';
			dbuff[j] = '\0';

			if (strcmp(cbuff, dbuff) != 0) printf("1 - %s\n2 - %s\n", cbuff, dbuff);

			i = j = 0;

			while (c != '\n') c = getc(one);
			while (d != '\n') d = getc(two);

			continue;

		}

		cbuff[i++] = c;
		dbuff[j++] = d;

	}

}

