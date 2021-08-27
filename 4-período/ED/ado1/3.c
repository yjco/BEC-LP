#include <stdio.h>

int euclidesI(int x, int y) {

	int resto = 0;
	while (y != 0) {
		resto = x % y;
		x = y;
		y = resto;
	}

	return x;

}

int euclidesR(int x, int y) {

	int resto = x % y;
	return (resto == 0) ? y : euclidesR(y, resto);

}

int main() {

	printf("Iterativo: %d\n", euclidesI(10, 6));
	printf("Recursivo: %d\n", euclidesR(10, 6));
	return 0;

}
