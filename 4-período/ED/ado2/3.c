#include <stdio.h>


void bsort(int *v, int n) {

	if (n == 1) return;

	int t, i;
	for (i = 0; i < n-1; i++) {

		if (v[i] > v[i+1]) {
			t = v[i];
			v[i] = v[i+1];
			v[i+1] = t;
		}

	}

	bsort(v, n-1);

}

int main() {

	int v[] = { 1, 4, 6, 4, 2, 9, 0, 80 };
	int n = sizeof(v) / sizeof(v[0]);
	bsort(v, n);

	for (int i = 0; i < n; i++) printf("%d ", v[i]);
	printf("\n");

	return 0;

}
