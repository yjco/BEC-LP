#include <stdio.h>


int adj(int* u, int nu, int* v, int nv) {
	int i, j; i = nu;
	while (--i >= 0 && (j = nv)) while (--j >= 0) if (u[i] == v[j]) return 1;
	return 0;
}


int main() {

	int u[5] = { 1, 3, 5, 7, 11 };
	int v[3] = { 2, 6, 11 };

	printf("%s\n", (adj(u, 5, v, 3)) ? "TRUE" : "FALSE");

	return 0;

}
