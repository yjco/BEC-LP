#include <stdio.h>

/*
 * Excercise 1-8 (P. 21)
 * Write a program to count blanks, tabs and new lines
 *
 */

int main() {

	int c, b, t, n;
	
	b = 0;
	t = 0;
	n = 0;

	while ((c = getchar()) != EOF) {
	
		switch (c) {
		
			case '\b' :
				b++;
				break;

			case '\t' :
				t++;
				break;

			case '\n' :
				n++;
				break;
		
		}
	
	}

	printf("Count of:\n- Blanks = %d\n- Tabs = %d\n- New Liness = %d\n", b, t, n);

}
