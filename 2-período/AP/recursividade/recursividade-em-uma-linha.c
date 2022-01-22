/**
 *
 * Funções recursivas com uma só linha por diversão
 *
 */

#include <stdio.h>

/** FATORAÇÃO
 * x = número para calcular o fatorial
 */
int fat(int x) {
	return (x == 1) ? x : x * fat(x-1);
}

/** BUSCA BINÁRIA
 * x = número a ser buscado
 * v = vetor
 * i = início do vetor
 * f = fim do vetor
 *
 ** TRADUÇÃO
 *
 * if (i > f) return -1;
 *
 * int m = (i+f)/2;
 * if (v[m] == x) return m;
 *
 * if (x < v[m])
 * 	return bbin(x, v, i, m-1);
 * else
 * 	return bbin(x, v, m+1, f);
 *
 */
int bbin(int x, int v[], int i, int f) {
	return (i > f) ? -1 : (v[(i+f)/2] == x) ? (i+f)/2 : (x < v[(i+f)/2]) ? bbin(x, v, i, ((i+f)/2)-1) : bbin(x, v, ((i+f)/2)+1, f);
}

/** POTÊNCIA
 * x = base
 * n = expoente
 */
int pot(int x, int n) {
	return (n == 1) ? x : x * pot(x, n-1);
}

/** MENOR NÚMERO
 * v = vetor
 * t = tamanho do vetor - 1
 */
int men(int v[], int t) { // inverter > para < se quiser o maior elemento
	return (t == 0) ? v[t] : (men(v, t-1) > v[t]) ? v[t] : men(v, t-1);
}

/** SOMA VALORES DO VETOR
 * v = vetor
 * t = tamanho do vetor - 1
 */
int soma(int v[], int t) {
	return (t == 0) ? v[t] : v[t] + soma(v, t-1);
}

/** MÉDIA ARITMÉTICA
 * v = vetor
 * t = tamanho do vetor - 1
 * m = tamanho
 */
float meda(int v[], int t, int m) {
	return (t == 0) ? v[t]/m : (v[t]/m) + meda(v, t-1, m);
}

/** SEQUÊNCIAS METÁLICAS
 * n = quantos imprimir
 * r = relação
 */
int meta(int n, int r) {
	return (n == 0 || n == 1) ? n : meta(n-1+r, r) + meta(n-2+r, r);
}

/** ALGORÍTMO DE EUCLIDES
 * x = núemro inteiro
 * y = outro número inteiro
 */
int reuclides(int x, int y) {
	return (x == 0) ? y : (y == 0) ? x : reuclides((x > y) ? x % y : y % x, (x > y) ? y : x);
}

int main() {
	return 0;
}
