#include <stdio.h>
#include <stdarg.h>

/*
 * Exercise 7-3 (P. 128)
 * Apprimorate minprintf()
 */

void minprintf(char *fmt, ...);

int main() {

	minprintf("Test %c\n", '6');

}

void minprintf(char *fmt, ...) {

	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);

	for (p = fmt; *p; p++) {

		if (*p != '%') {

			putchar(*p);
			continue;

		}

		switch (*++p) {

			case 'd' :
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;

			case 'f' :
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;

			case 's' :
				for (sval = va_arg(ap, char *); *sval; sval++) putchar(*sval);
				break;

			case 'c' :
				ival = va_arg(ap, int);
				printf("%c", ival);
				break;

			default :
				putchar(*p);
				break;

		}

	}

	va_end(ap);

}

