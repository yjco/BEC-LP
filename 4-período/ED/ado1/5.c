#include <stdio.h>


void swap(int* x, int* y) { int a = *x; *x = *y; *y = a; }

void invert(int* a, int l, int t) {

	if (t / 2 >= l) return;

	swap(a, a+l-1);
	invert(a+1, l-2, t);

}


int main() {

	int array[5] = { 1, 2, 3, 4, 5 };
	invert(array, 5, 5);

	for (int i = 0; i < 5; i++) printf("%d ", array[i]);
	printf("\n");

}
