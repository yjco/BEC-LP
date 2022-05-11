#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 4-4 (P. 68)
 * Add commands to print the stack without pop(), to duplicate, swap the top 2 elements and clear the stack
 */

#define	MAXOP	100
#define	NUMBER	'0'

int getop(char []);
void push(double);
double pop(void);

void pstack();
void dstack();
void sstack();
void cstack();

int main() {

	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {

		switch (type) {

			case NUMBER :
				push(atof(s));
				break;

			case '+' :
				push(pop() + pop());
				break;

			case '*' :
				push(pop() * pop());
				break;

			case '-' :
				op2 = pop();
				push(pop() - op2);
				break;

			case '/' :
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor\n");
				break;

			case '%' :
				op2 = pop();
				if (op2 != 0.0)
					push((int)pop() % (int)op2);
				else
					printf("Error: zero divisor\n");
				break;

			case 'p' :
				pstack();
				push(0.0);
				break;

			case 'd' :
				dstack();
				break;

			case 's' :
				sstack();
				break;

			case 'c' :
				cstack();
				break;

			case '\n' :
				printf("\t%.8g\n", pop());
				break;

			default :
				printf("Error: unknown command %s\n", s);
				break;

		}

	}

	return 0;

}

#define	MAXVAL	100

int sp = 0;
double val[MAXVAL];

void push(double f) {

	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full, can't push %g\n", f);

}

double pop() {

	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}

}

void pstack() {

	printf("Stack: ");

	for (int i = 0; i < sp; i++) printf("%g ", val[i]);

	printf("\n");

}

void dstack() {

	int spc = sp;
	for (int i = 0; i < spc; i++) push(val[i]);

}

void sstack() {

	int last = pop();
	int laxt = pop();

	push(last);
	push(laxt);

}

void cstack() {

	int spc = sp;
	for (int i = 0; i < spc; i++) pop();

}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {

	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	if (!isdigit(c) && c != '.') return c;

	i = 0;

	if (isdigit(c)) while (isdigit(s[++i] = c = getch()));
	if (c == '.') while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';

	if (c != EOF) ungetch(c);

	return NUMBER;

}

#define	BUFSIZE	100

char buf[BUFSIZE];
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

