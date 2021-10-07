#include <stdio.h>

void invert(int v[], int s) {

	if (s == 0 || s == 1) return;

	int t = v[0];
	v[0] = v[s-1];
	v[s-1] = t;

	invert(&v[1], s-2);

}

int main() {

	int v[] = { 0, 1, 2, 3, 4, 5 };
	int s = sizeof(v) / sizeof(int);

	for (int i = 0; i < s; i++) printf("%d ", v[i]);
	printf("\n");

	invert(v, s);

	for (int i = 0; i < s; i++) printf("%d ", v[i]);
	printf("\n");

}
