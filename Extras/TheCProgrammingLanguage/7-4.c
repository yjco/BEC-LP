#include <stdio.h>
#include <stdarg.h>

/*
 * Exercise 7-4 (P. 130)
 * Write a simplified version of scanf()
 */

void minprintf(char *fmt, ...);

int main() {

	minscanf("Test %c\n", '6');

}

void minscanf(char *fmt, ...) {

	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);

	for (p = fmt; *p; p++) {

		if (*p != '%') continue;

		switch (*++p) {

			case 'd' :
				ival = va_arg(ap, int);
				scanf("%d", ival);
				break;

			case 'f' :
				dval = va_arg(ap, double);
				scanf("%f", dval);
				break;
	
			case 'c' :
				ival = va_arg(ap, int);
				scanf("%c", ival);
				break;

		}

	}

	va_end(ap);

}

