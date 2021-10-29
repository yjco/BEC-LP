#include <stdio.h>

#define msize 5


int vg(int m[msize][msize], int v) {

	v -= 1;
	int g = 0;
	for (int i = 0; i < msize; i++) g += (m[i][v] != 0) ? 1 : 0; 

	return g;

}

int main() {

	int madj[msize][msize] = { { 0, 1, 0, 1, 0 },
				   { 0, 1, 0, 1, 0 },
				   { 0, 1, 0, 1, 0 },
				   { 0, 1, 0, 1, 0 },
				   { 0, 1, 0, 1, 0 } };

	printf("Grau: %d\n", vg(madj, 2));

	return 0;

}
