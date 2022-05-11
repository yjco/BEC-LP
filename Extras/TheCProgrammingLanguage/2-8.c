#include <stdio.h>

/*
 * Exercise 2-8 (p. 46)
 * Rotate a integer n bits to the right.
 */

unsigned rightrot(int x, int n) {

    return (x >> n) | ((~(~0 << n) & x) << (8 - n));

}

int main() {
 
   printf("%d\n", rightrot(60, 3));

}
