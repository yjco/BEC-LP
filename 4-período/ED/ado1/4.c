#include <stdio.h>

int maior(int v[], int t) {
	return (t == 0) ? v[t] : (maior(v, t-1) < v[t]) ? v[t] : maior(v, t-1);
}

int main() {

	int v[] = { 4, 0, 8, 4, 6 };
	printf("%d\n", maior(v, 4));
	return 0;

}
