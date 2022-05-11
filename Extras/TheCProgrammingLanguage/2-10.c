#include <stdio.h>

/*
 * Exercise 2-10 (P. 48)
 * Re-write the function lower to use ternary condition
 */

int lower(int c) {
    
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c ;
    
}

int main() {

	printf("%c\n", lower('Z'));

}
