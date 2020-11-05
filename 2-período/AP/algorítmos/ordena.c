#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALG	"obol"	// Define qual algorítmo usar

// Vetor para ser ordenado
int arr[] = { 3, 65536, -10000, 6, 7, 4, 5, 5, 18 };

// Imprime vetor
//
// v[] é o vetor e l seu tamanho
void vprint(int v[], int l) {

	int i = 0;
	while (i < l) printf("%d ", v[i++]);
	putchar('\n');

}


/**************************************
 *				      *
 * ALGORÍTIMOS DE ORDENAÇÃO POR BOLHA *
 *				      *
 **************************************/

// Ordena vetor
//
// v[] é o vetor e l seu tamanho 
void obol(int v[], int l) {

	int t, i, j;
	for (i = l-1; i > 0; i--) {

		for (j = 0; j < i; j++) {

			if (v[j] > v[j+1]) {

				t = v[j];
				v[j] = v[j+1];
				v[j+1] = t;


			}


		}

	}

	vprint(v, l);

}


/**********
 *	  *
 * INÍCIO *
 *	  *
 **********/

// Retorna 0, 2 se algorítmo não existir
int main() {

	int ret = 0;
	if (strcmp(ALG, "obol") == 0) obol(arr, sizeof(arr)/sizeof(int));
	else {
		printf("Não há uma função para o algorítmo: %s\n", ALG);
		exit(2);
	}

	return 0;

}
