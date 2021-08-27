#include <stdio.h>

void inv(int v[], int n) {

	if (n == 0) return;

	int t = 0;
	for (int i = 0; i < n-1; i++) {
		t = v[i];
		v[i] = v[i+1];
		v[i+1] = t;
	}

	inv(v, n-1);

}

int main() {

	int v[] = { 1, 2, 3, 4, 5 };
	inv(v, 5);

	for (int i = 0; i < 5; i++) printf("%d ", v[i]);
	printf("\n");

	return 0;

}
