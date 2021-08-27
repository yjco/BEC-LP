#include <stdio.h>

/**
 * v : vetor de inteiros
 * n : tamanho de v
 * m : vetor onde a contagem será feita
 */
void moda(int v[], int n, int m[]) {

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[i] == v[j]) m[i]++;
		}
	}

}

int main() {

	int v[] = { 1, 1, 2, 2, 5 };
	int m[5] = { 1, 1, 1, 1, 1 };

       	moda(v, 5, m);

	int maior = 1;
	for (int i = 0; i < 5; i++) {
		if (m[i] > maior) maior = m[i];
	}

	for (int i = 0; i < 5; i++) {
		if (m[i] == maior) {
			printf("%d: %d\n", v[i], m[i]);
		}
	}

	return 0;

}
