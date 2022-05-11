#include <stdio.h>

/*
 * Exercise 2-6 (P. 46)
 * Get the p rightmost bits of x and set at n rightmost bits of y
 */

unsigned setbit(unsigned x, int p, int n, unsigned y) {
    return (((~(~0 << n)) << (p + 1 - n)) & x) >> (p + 1 - n) | ((~0 << n) & y);
}

int main() {
    
    printf("%d\n", setbit(60, 4, 3, 15));
    
}
