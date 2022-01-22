#include <stdio.h>
#include <stdlib.h>


int* cmoda(int* a, int* l) {

	int s = 1;
	int** m = malloc(sizeof(int) * *l);

	m[0] = malloc(sizeof(int) * 2);
	m[0][0] = a[0];
	m[0][1] = 1;

	int flag;
	for (int i = 1; i < *l; i++) {

		flag = 1;
		for (int j = 0; j < s; j++) {

			if (a[i] == m[j][0]) { 
				m[j][1]++;
				flag = 0;
			}

		}

		if (flag) {
			m[s] = malloc(sizeof(int) * 2);
			m[s][0] = a[i];
			m[s][1] = 1;
			s++;
		}

	}

	int b = 0;
	for (int i = 0; i < s; i++) if (b < m[i][1]) b = m[i][1];

	int j = 0;
	int* n = malloc(sizeof(int) * s);
	for (int i = 0; i < s; i++) if (m[i][1] == b) n[j++] = m[i][0];

	free(m);
	*l = j;
	return n;

}

int main() {

	int array[7] = { 1, 1, 5, 3, 2, 2, 1 };
	int length = 7;

	int* moda = cmoda(array, &length);

	printf("MODA: ");
	for (int i = 0; i < length; i++) printf("%d ", *(moda++));
	printf("\n");

}
