#include <stdio.h>

/**
 * v : vetor de inteiros
 * n : tamanho de v
 */
int ordem(int v[], int n) {

	int o = 4;
	for (int i = 0; i < n-1; i++) {
		switch (o) {
			case 4 :
				//printf("%d %d: %d != %d\n", i, o, v[i], v[i+1]);
				if (v[i] != v[i+1]) o--;
				else break;
			case 3 :
				//printf("%d %d: %d < %d\n", i, o, v[i], v[i+1]);
				if (v[i] < v[i+1]) o--;
				else break;
			case 2 :
				//printf("%d %d: %d > %d\n", i, o, v[i], v[i+1]);
				if (v[i] > v[i+1]) o--;
				else break;
			case 1 :
				return o;
		}
		//printf("Next loop\n");
	}
	return o;

}

int main() {

	int v[] = { 0, 2, 1 }; // 1
	//int v[] = { 0, 1, 2 }; // 2
	//int v[] = { 2, 1, 0 }; // 3
	//int v[] = { 0, 0, 0 }; // 4

	printf("%d\n", ordem(v, 3));
	return 0;

}
