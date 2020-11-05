#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALG	"bbin"	// Define qual algorítmo usar
#define BUSCAR 	1	// Elemento a ser buscado

// Vetor onde a busca será feita
int arr[] = { -10000, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255, 65536 };


/**********************************
 *				  *
 * ALGORÍTMOS DE BUSCA SEQUENCIAL *
 *				  *
 **********************************/

// Procura elemento por elemento por um valor dado e retorna sua posição, -1 se não estivar no vetor
//
// v[] é o vetor, l seu tamanho e n o valor procurado
int bseq(int v[], int l, int n) {

	for (l--; l >= 0; l--) if (v[l] == n) return l;
	return -1;

}

// Procura elemento por elemento por um valor dado e retorna sua posição, -1 se não estivar no vetor
// É necessário que o vetor esteja ordenado
//
// v[] é o vetor, l seu tamanho e n o valor procurado
int bseqo(int v[], int l, int n) {

	for (l--; l >= 0 && v[l] > n; l--);
	return (v[l] == n) ? l : -1;

}


/*******************************
 *			       *
 * ALGORÍTMOS DE BUSCA BINÁRIA *
 *			       *
 *******************************/

// Procura elemento por elemento por um valor dado e retorna sua posição, -1 se não estivar no vetor
// É necessário que o vetor esteja ordenado
//
// v[] é o vetor, l seu tamanho e n o valor procurado
int bbin(int v[], int l, int n) {

	--l;
	int i = 0, m = 0;
	for (m = (i+l)/2; i <= l; m=(i+l)/2) {

		if (v[m] == n) return m;
		else
		if (v[m] > n) l = m - 1;
		else
		if (v[m] < n) i = m + 1;

	}
	return -1;

}


/**********
 *	  *
 * INÍCIO *
 *	  *
 **********/

// Retorna 0 se encontrado, 1 se não, 2 se algorítmo não existir
int main() {

	int ret = 0;
	if (strcmp(ALG, "bseq") == 0) ret = bseq(arr, sizeof(arr)/sizeof(int), BUSCAR);
	else if (strcmp(ALG, "bseqo") == 0) ret = bseqo(arr, sizeof(arr)/sizeof(int), BUSCAR);
	else if (strcmp(ALG, "bbin") == 0) ret = bbin(arr, sizeof(arr)/sizeof(int), BUSCAR);
	else {
		printf("Não há uma função para o algorítmo: %s\n", ALG);
		exit(2);
	}

	if (ret == -1)
		printf("Valor não está no array\n");
	else
		printf("Valor na posição: %d\n", ret);

	return (ret == -1) ? 1 : 0;

}
