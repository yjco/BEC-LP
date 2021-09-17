#include <stdio.h>


int bbin(int *v, int n, int p) {

	int i;
	int a = 0;
	while (a <= n) {

		i = (a + (n-1)) / 2;

		if (v[i] == p) return i;
		else if (v[i] > p) n = i-1;
		else if (v[i] < p) a = i+1;

	}

	return -1;

}

int main() {

	int v[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(v) / sizeof(v[0]);
	printf("%d\n", bbin(v, n, 4));

	return 0;

}
