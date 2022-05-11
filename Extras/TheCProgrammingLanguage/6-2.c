#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Exercise 6-2 (P. 117)
 * Write a program to print aphabetical order variable names from a C program which the first n chars are equal
 */

#define	DEFNCHAR	6
int nchar = DEFNCHAR;

int gettype();
void addStr(char *s);
void prtStr();

int main(int argc, char *argv[]) {

	if (argc > 1) {

		if (isdigit(*argv[1])) nchar = (int)*argv[1] - '0';
		else {

			printf("Set a numerical value from 0 to 9\n");
			return 1;

		}

	}

	gettype();
	prtStr();

}

#define	BUFFER	100
char buff[BUFFER];
int ind = 0;

int gettype() {

	char c;
	int b;

	while((c = getchar()) != EOF) {

		if (c == '\n') {

			buff[ind] = '\0';
			ind = 0;
		
			if (strlen(buff) < nchar) continue;

			addStr(buff);
			continue;

		}

		buff[ind++] = c;

	}

}

char str[30][BUFFER];
int dni = 0;

void addStr(char *s) {

	strcpy(str[dni++], s);

}

void prtStr() {

	char *lessStr[dni];
	int lessInd;

	for (int i = 0; i < dni; i++) {

		lessInd = 0;

		for (int j = 0; j < dni; j++)
			if (strcmp(str[i], str[j]) > 1) lessInd++;

		lessStr[lessInd] = str[i];

	}

	putchar('\n');

	for (int i = 0; i < dni; i++) printf("%s\n", lessStr[i]); 

}

