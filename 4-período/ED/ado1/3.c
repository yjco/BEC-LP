#include <stdio.h>


int reuclides(int x, int y) {
	return (x == 0) ? y : (y == 0) ? x : reuclides((x > y) ? x % y : y % x, (x > y) ? y : x);
}

int ieuclides(int x, int y) {

	if (x == 0) return y;
	if (y == 0) return x;

	while (x != 0 && y != 0) { 
		if (x > y) x %= y;
		else y %= x;
	}

	return (x == 0) ? y : x;

}


int main() {
	printf("Greatest Common Divider: %d\n", ieuclides(20, 8));
}
