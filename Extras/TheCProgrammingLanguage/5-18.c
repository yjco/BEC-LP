#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Exercise 5-18 (P. 104)
 * Make dvl() recover from input errors
 */

#define	MAXTOKEN	100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int getch(void);
void ungetch(int);

extern int tokentype;
extern char token[];
int prevtoken = NO;

int main() {

	while (gettoken() != EOF) {

		strcpy(datatype, token);
		out[0] = '\0';

		dcl();

		if (tokentype != '\n') printf("syntax error \n");
		printf("%s: %s %s \n", name, out, datatype);

	}

	return 0;

}

void dcl(void) {

	int ns;

	for (ns = 0; gettoken() == '*'; ) ns++;
	dirdcl();

	while (ns-- > 0) strcat(out, " pointer to");

}

void dirdcl(void) {

	int type;

	if (tokentype == '(') {

		dcl();

		if (tokentype != ')') errmsg("error: missing )\n");

	} else if (tokentype == NAME)
		strcpy(name, token);
	else errmsg("error: expected name of (dcl)\n");

	while ((type = gettoken()) == PARENS || type == BRACKETS) {

		if (type == PARENS) strcat(out, " function returning");
		else {

			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");

		}

	}

}

void errmsg(char *msg) {

	printf("%s", msg);
	prevtoken = YES;

}

int gettoken(void) {

	int c, getch(void);
	void ungetch(int);
	char *p = token;

	if (prevtoken == YES) {

		prevtoken = NO;
		return tokentype;

	}

	while ((c = getch()) == ' ' || c == '\t');

	if (c == '(') {

		if ((c = getch()) == ')') {

			strcpy(token, "()");
			return tokentype = PARENS;

		} else {

			ungetch(c);
			return tokentype = '(';

		}

	} else if (c == '[') {

		for (*p++ = c; (*p++ = getch()) != ']'; );

		*p = '\0';
		return tokentype = BRACKETS;

	} else if (isalpha(c)) {

		for (*p++ = c; isalnum(c = getch()); ) *p++ = c;

		*p = '\0';
		ungetch(c);

		return tokentype = NAME;

	} else return tokentype = c;

}

#define	BUFSIZE	100

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {

	return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch(int c) {

	if (bufp >= BUFSIZE)
		printf("Ungetch: too many characters\n");
	else
		buf[bufp++] = c;

}
