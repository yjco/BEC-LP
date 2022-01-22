#include <stdio.h>


int order(int* a, int l) {

	int aux;
	int order = -1;
	for (int i = 0; i < l-1; i++) {

		aux = a[i+1] - a[i];

		if (aux > 0) {
			if (order == 3) return 1;
			order = 2;
		} else if (aux < 0) { 
			if (order == 2) return 1;
			order = 3;
		} else if (aux == 0) { 
			order = 4;
		}

	}

	return order;

}

int main() {

	int array[5] = { 8, 9, 5, 6, 1 };
	switch (order(array, 5)) {
		case 1:
			printf("%s\n", "DESORDENADO");
			break;
		case 2:
			printf("%s\n", "CRESCENTE");
			break;
		case 3:
			printf("%s\n", "DESCRESCENTE");
			break;
		case 4:
			printf("%s\n", "CONSTANTE");
			break;
	}

}
