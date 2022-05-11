#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Exercise 7-8 (P. 135)
 * Write a program to print files with titles and pages
 */

int main(int argc, char *argv[]) {

	if (argc < 1) {
	
		printf("Error: you must specify 1 file!\n");	
		exit(1);

	}

	int c, i;
	i = 1;

	for (FILE *f = fopen(argv[i], "r"); i < argc; i++) {

		printf("%s\n", argv[i]);

		while ((c = getc(f)) != EOF) putchar(c);

		printf("\t\t\t%d\n\n", i);

		fclose(f);

	}

}

