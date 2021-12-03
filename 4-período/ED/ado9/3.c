#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int dad(int i) { return i/2; }
int left(int i) { return i*2; }
int right(int i) { return i*2+1; }
void swap(int* i, int* j) { int a = *i; *i = *j; *j = a; }


void up(int* heap, int i) {

	int d = dad(i);
	if (d >= 1 && heap[i] > heap[d]) {
		swap(&heap[i], &heap[d]);
		up(heap, d);
	}

}

int insert(int* heap, int i, int n) {

	heap = (int*)realloc(heap, sizeof(int) * (n+2));
	heap[++n] = i;

	up(heap, n);

	return n;

}

void down(int* heap, int i, int n) {

	int l = left(i);
	int r = right(i);
	int big = i;

	if ((l <= n) && (heap[l] > heap[i])) big = l;
	if ((r <= n) && (heap[r] > heap[big])) big = r;

	if (big != i) {
		swap(&heap[i], &heap[big]);
		down(heap, big, n);
	}

}

int delete(int* heap, int n) {

	heap[1] = heap[n--];
	heap = (int*)realloc(heap, sizeof(int) * (n+1));

	down(heap, 1, n);

	return n;

}

void showArray(int* heap, int n) { for (int i = 1; i <= n; i++) printf("[%d]%d\n", i, heap[i]); }
void show(int* heap, int p, int n) {

	printf("(");
	if (p <= n) {
		printf("%i", heap[p]);
		show(heap, left(p), n);
		show(heap, right(p), n);
	}
	printf(")");

}

void buildUp(int* heap, int n) { for (int i = left(1); i <= n; i++) up(heap, i); }
void buildDown(int* heap, int n) { for (int i = dad(n); i >= 1; i--) down(heap, i, n); }
void heapSort(int *heap, int n) {

	int j = n;
	//buildDown(heap, n);
	buildUp(heap, n);
	for (int i = n; i > 1; i--) {
		swap(&heap[i], &heap[1]);
		down(heap, 1, --j);
	}

}

int* heapMerge(int* h1, int n1, int* h2, int n2) {

	int n = n1+n2;
	int* h = malloc(n * sizeof(int));

	memcpy(h, h1, (n1+1) * sizeof(int));
	memcpy(h+n1+1, h2+1, n2 * sizeof(int));

	return h;

}


int main() {

	int n1 = 0;
	int* h1 = (int*)malloc(sizeof(int) * (n1+1));

	n1 = insert(h1, 4, n1);
	n1 = insert(h1, 2, n1);
	n1 = insert(h1, 5, n1);
	n1 = insert(h1, 3, n1);
	n1 = insert(h1, 1, n1);
	n1 = insert(h1, 6, n1);
	n1 = insert(h1, 8, n1);
	n1 = insert(h1, 7, n1);

	int n2 = 0;
	int* h2 = (int*)malloc(sizeof(int) * (n2+1));

	n2 = insert(h2, 5, n2);
	n2 = insert(h2, 3, n2);
	n2 = insert(h2, 17, n2);
	n2 = insert(h2, 10, n2);
	n2 = insert(h2, 84, n2);
	n2 = insert(h2, 19, n2);
	n2 = insert(h2, 6, n2);
	n2 = insert(h2, 22, n2);
	n2 = insert(h2, 9, n2);

	int n = n1+n2;
	int* h = heapMerge(h1, n1, h2, n2);
	show(h, 1, n); printf("\n"); showArray(h, n);

	heapSort(h, n);
	show(h, 1, n); printf("\n"); showArray(h, n);

	return 0;

}
