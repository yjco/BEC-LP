#include <stdio.h>

/*
 * Exercise 3-2 (P. 53)
 * Write a function to convert \n to \\n and \t to \\t and vice-versa
 */

#define	IND	13

void escape(char s[], char t[]);
void epacse(char s[], char t[]);

int main() {

	char str[] = { 'I', 'M', '\t', 'F', 'R', 'E', 'E', '\n', 'F', 'O', 'S', 'S', '\n' };
	char rts[IND + 3];
	char tsr[IND + 3];

	escape(rts, str);

	for (int i = 0; i < IND + 3; i++) {

		putchar(rts[i]);

	}

	putchar('\n');

	epacse(tsr, rts);

	for (int i = 0; i < IND; i++) {

		putchar(tsr[i]);

	}

	putchar('\n');
}

void escape(char s[], char t[]) {

	int j = 0;

	for (int i = 0; i < IND; i++) {

		switch(t[i]) {

			case '\n' :
				s[j++] = '\\';
				s[j++] = 'n';
				break;

			case '\t' :
				s[j++] = '\\';
				s[j++] = 't';
				break;

			default :
				s[j++] = t[i];
				break;

		}

	}

}

void epacse(char s[], char t[]) {

	int j = 0;

	for (int i = 0; i < IND; i++) {

		if (t[j] == '\\') {

			switch(t[++j]) {

				case 'n' :
					s[i] = '\n';
					break;

				case 't' :
					s[i] = '\t';
					break;

				default :
					s[i] = t[j];
					break;


			}

			j++;

		} else {

			s[i] = t[j++];

		}

	}

}

