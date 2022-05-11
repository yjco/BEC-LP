#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Exercise 6-4 (P. 117)
 * Write a program to print words is occurrence order
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

	for (int i = 0; i < dni; i++) 
		printf("%d - %s\n", i, str[i]);

}

