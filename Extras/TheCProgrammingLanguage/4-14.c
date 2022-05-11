#include <stdio.h>

/*
 * Exercise 4-14 (P. 76)
 * Define a macro swap(t, x, y) that interchanges two arguments of type t
 */

#define	swap(t, x, y)	{		\
				t = x;	\
				x = y;	\
				y = t;	\
			}

int main() {

	int a, b, c;

	b = 2;
	c = 3;

	swap(a, b, c);

	printf("%d - %d\n", b, c);

}

