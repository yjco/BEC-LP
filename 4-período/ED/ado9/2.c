#include <stdio.h>
#include <stdlib.h>


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

void showArray(int* heap, int n) { for (int i = 1; i <= n; i++) printf("%d ", heap[i]); }
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
		show(heap, 1, n); printf("\n"); showArray(heap, n); printf("\n\n");
	}

}


int main() {

	int n = 0;
	int* heap = (int*)malloc(sizeof(int) * (n+1));

	n = insert(heap, 5, n);
	n = insert(heap, 3, n);
	n = insert(heap, 17, n);
	n = insert(heap, 10, n);
	n = insert(heap, 84, n);
	n = insert(heap, 19, n);
	n = insert(heap, 6, n);
	n = insert(heap, 22, n);
	n = insert(heap, 9, n);

	show(heap, 1, n); printf("\n"); showArray(heap, n); printf("\n\n");
	heapSort(heap, n);

	return 0;

}
