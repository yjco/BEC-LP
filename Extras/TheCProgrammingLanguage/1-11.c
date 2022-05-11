#include <stdio.h>

/*
 * Exercise 1-11 (P. 23)
 * How would you test the word counting program? Which inputs are most likely to uncover bugs?
 *
 */

#define	IN	1	/* Inside the word */
#define	OUT	0	/* Outside the word */

int main() {

	int c, state, cc, wc, lc;
	cc = wc = lc = 0;

	state = OUT;

	while ((c = getchar()) != EOF) {
	
		++cc;

		if (c == '\n') ++lc;

		if (c == ' ' || c == '\n' || c == '\t') {
		
			state = OUT;

		} else if (state == OUT) {
		
			state = IN;
			++wc;
		
		}
	
	}

	printf("Chars: %d\nWords: %d\nLines: %d\n", cc, wc, lc);

}
