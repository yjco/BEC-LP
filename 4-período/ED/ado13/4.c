#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int val;
	struct node* next;
} NODE;

typedef struct hode {
	int val;
	int weight;
} HODE;

typedef struct graph {
	int n;
	NODE* begin;
	int** matrix;
	int*** list;
} GRAPH;


GRAPH init() {

	GRAPH* g = (GRAPH*)malloc(sizeof(GRAPH));
	g->matrix = NULL;
	g->begin = NULL;
	g->list = NULL;
	g->n = 0;

	return *g;

}

void insertGraph(GRAPH* g, int val) {

	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->next = NULL;
	n->val = val;
	g->n++;

	if (g->begin == NULL) {
		g->begin = n;
		g->list = (int***)malloc(sizeof(int**));
		g->matrix = (int**)malloc(sizeof(int*));
		*g->list = NULL;
		*(g->matrix) = 0;
	} else {
		NODE* m = g->begin;
		while (m->next != NULL) {
			if (m->val == val) return;
			m = m->next;
		}
		m->next = (NODE*)malloc(sizeof(NODE));
		*(m->next) = *n;

		for (int i = 0; i < g->n; i++) {
			*(g->matrix+i) = (int*)malloc(sizeof(int) * g->n);
			*(g->list+i) = (int**)malloc(sizeof(int*) * g->n);
		}

		for (int i = 0, j = -1; i < g->n; i++) {
			*(*((g->matrix)+i)+g->n-1) = 0;
			*(*((g->matrix)+g->n-1)+i) = 0;
			while (*(*(g->list+i)+(++j)) != NULL);
			*(*((g->list)+i)+j) = NULL;
		}
	}

}

int find(GRAPH* g, int v) {

	int i = 0;
	for (NODE* m = g->begin; m != NULL; m = m->next) {
		if (m->val == v) return i;
		i++;
	}
	return -1;

}

NODE* get(GRAPH* g, int v) {
	for (NODE* m = g->begin; m != NULL; m = m->next) if (m->val == v) return m;
	return NULL;
}

int connected(GRAPH* g, int n, int m) { return (*(*(g->matrix+find(g, n))+find(g, m)) != 0) ? 1:0; }
void connect(GRAPH* g, int v1, int v2, int weight, int both) {

	int n1 = find(g, v1);
	int n2 = find(g, v2);

	if (n1 == -1 || n2 == -1) return;

	*(*((g->matrix)+n1)+n2) = weight;

	int* cell = (int*)malloc(sizeof(int) * 2);
	*cell = v2;
	*(cell+1) = weight;

	int i = -1;
	while (*(*((g->list)+n1)+(++i)) != NULL);
	*(*((g->list)+n1)+i) = cell;

	if (both) {
		*(*((g->matrix)+n2)+n1) = weight;

		cell = (int*)malloc(sizeof(int) * 2);
		*cell = v1;
		*(cell+1) = weight;
		*(*((g->list)+n2)+i) = cell;
	}

}

void showGraph(GRAPH* g) {

	int i = 0;
	printf("    ");
	for (NODE* m = g->begin; m != NULL; m = m->next) {
		printf("%d  ", m->val);
		i++;
	}
	printf("\n  +-");

	while (i-- != 0) printf("---");
	printf("\n");

	for (NODE* m = g->begin; m != NULL; m = m->next) {
		i++;
		printf("%d | ", m->val);
		for (int j = 0; j < g->n; j++) printf("%d  ", *(*(g->matrix+i)+j));
		printf("\n");
	}

}

void showList(GRAPH* g) {

	int flag;
	NODE* n = g->begin;
	for (int i = 0; i < g->n; i++, n=n->next) {
		flag = 1;
		printf("%d: ", n->val);
		for (int j = 0; *(*((g->list)+i)+j) != NULL; j++) {
			printf("%d[%d] > ", *(*(*((g->list)+i)+j)+0), *(*(*((g->list)+i)+j)+1));
			flag = 0;
		}
		if (flag) printf(" ");
		printf("\b\b  \n");
	}

}

void showColors(GRAPH* g, int* colors, int* distance) {

	for (NODE* m = g->begin; m != NULL; m = m->next) printf("%d ", m->val);
	printf("\n");

	for (int i = 0; i < g->n; i++) printf("%d ", *(colors+i));
	printf("\n");

	for (int i=0; i < g->n; i++) printf("%c ",(*(distance+i) == -1) ? '.' : *(distance+i)+'0');
	printf("\n");

}

void visit(GRAPH* g, int n, int* colors, int* distance) {

	int fn = find(g, n);
	(*(colors+fn))++;
	(*(distance+fn))++;

	showColors(g, colors, distance); printf("\n");

	int i = 0;
	int* aux = (int*)malloc(sizeof(int) * g->n);
	for (NODE* m = g->begin; m != NULL; m = m->next) {
		if (connected(g, n, m->val) && *(colors+find(g, m->val)) == 0) {
			*(aux+(i++)) = m->val;
			*(distance+find(g, m->val)) = *(distance+fn);
			showColors(g, colors, distance); printf("\n");
		}
	}

	for (int j = 0; j < i; j++) visit(g, *(aux+j), colors, distance);
	(*(colors+fn))++;

}

void wide(GRAPH* g, int begin) {

	if (g->begin == NULL) return;

	int* colors = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(colors+i) = 0;

	int* distance = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(distance+i) = -1;

	showColors(g, colors, distance); printf("\n");
	visit(g, begin, colors, distance);
	showColors(g, colors, distance);

	free(colors);

}

int dad(int i) { return i/2; }
int left(int i) { return i*2; }
int right(int i) { return i*2+1; }
void swap(HODE* i, HODE* j) { HODE a = *i; *i = *j; *j = a; }


void up(HODE* heap, int i) {

	int d = dad(i);
	if (d <= 1 && heap[i].weight < heap[d].weight) {
		swap(&heap[i], &heap[d]);
		up(heap, d);
	}

}

void down(HODE* heap, int i, int n) {

	int l = left(i);
	int r = right(i);
	int big = i;

	if ((l <= n) && (heap[l].weight > heap[i].weight)) big = l;
	if ((r <= n) && (heap[r].weight > heap[big].weight)) big = r;

	if (big != i) {
		swap(&heap[i], &heap[big]);
		down(heap, big, n);
	}

}

int insertHeap(HODE* heap, int i, int w, int n) {

	heap = (HODE*)realloc(heap, sizeof(HODE) * (n+2));
	heap[++n].val = i;
	heap[n].weight = w;

	up(heap, n);

	return n;

}

int delete(HODE* heap, int n) {

	heap[1] = heap[n--];
	heap = (HODE*)realloc(heap, sizeof(HODE) * (n+1));

	down(heap, 1, n);

	return n;

}

void showArray(HODE* heap, int n) { for (int i = 1; i <= n; i++) printf("%d ", heap[i].val); }
void showHeap(HODE* heap, int p, int n) {

	printf("(");
	if (p <= n) {
		printf("%i", heap[p].val);
		showHeap(heap, left(p), n);
		showHeap(heap, right(p), n);
	}
	printf(")");

}

void buildUp(HODE* heap, int n) { for (int i = left(1); i <= n; i++) up(heap, i); }
void buildDown(HODE* heap, int n) { for (int i = dad(n); i >= 1; i--) down(heap, i, n); }
void heapSort(HODE *heap, int n) {

	int j = n;
	buildDown(heap, n);
	//buildUp(heap, n);
	for (int i = n; i > 1; i--) {
		swap(&heap[i], &heap[1]);
		down(heap, 1, --j);
		showHeap(heap, 1, n); printf("\n"); showArray(heap, n); printf("\n\n");
	}

}

int dvisit(GRAPH* g, HODE* heap, int n, int* distance) {

	if (n == 0) return n;

	HODE* h = &heap[1];
	n = delete(heap, n);

	int p = find(g, h->val);
	if (*(*((g->list)+p)+0) == 0) return n;

	int q;
	int i = -1;
	while (*(*((g->list)+p)+(++i)) != NULL) {
		if (*(*(*((g->list)+p)+i)+1) < h->weight || *(distance+p) == 0) {
			q = find(g, *(*(*((g->list)+p)+i)+0));
			*(distance+q) += h->weight + *(*(*((g->list)+p)+i)+1);
			n = insertHeap(heap, *(*(*((g->list)+p)+i)+0), *(distance+q), n);
		}
		n = dvisit(g, heap, n, distance);
	}

}

void dijkstra(GRAPH* g, NODE* begin) {

	int n = 0;
	HODE* heap = (HODE*)malloc(sizeof(HODE) * (n+1));

	n = insertHeap(heap, begin->val, 0, n);

	int* distance = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(distance+i) = 0;

	dvisit(g, heap, n, distance);

	printf(">>> %d\n", begin->val);
	int p;
	for (NODE* m = g->begin; m != NULL; m = m->next) {
		p = find(g, m->val);
		if (*(distance+p) == 0) continue;
		printf("%d: %d\n", m->val, *(distance+p));
	}

}


int heapex() {

	int n = 0;
	HODE* heap = (HODE*)malloc(sizeof(HODE) * (n+1)); // heap sorted by weight

	/*n = insertHeap(heap, 5, n);
	n = insertHeap(heap, 3, n);
	n = insertHeap(heap, 17, n);
	n = insertHeap(heap, 10, n);
	n = insertHeap(heap, 84, n);
	n = insertHeap(heap, 19, n);
	n = insertHeap(heap, 6, n);
	n = insertHeap(heap, 22, n);
	n = insertHeap(heap, 9, n);*/

	n = insertHeap(heap, 10, 5, n);
	n = insertHeap(heap, 14, 5, n);
	n = insertHeap(heap, 19, 5, n);
	n = insertHeap(heap, 26, 5, n);
	n = insertHeap(heap, 31, 5, n);
	n = insertHeap(heap, 42, 5, n);
	n = insertHeap(heap, 27, 5, n);
	n = insertHeap(heap, 44, 5, n);
	n = insertHeap(heap, 35, 5, n);
	n = insertHeap(heap, 33, 5, n);

	showHeap(heap, 1, n); printf("\n"); showArray(heap, n); printf("\n\n");
	heapSort(heap, n);

	return 0;

}

int graphex() {

	GRAPH graph = init();

	insertGraph(&graph, 1);
	insertGraph(&graph, 2);
	insertGraph(&graph, 3);
	insertGraph(&graph, 4);
	insertGraph(&graph, 5);

	connect(&graph, 3, 5, 9, 0);
	connect(&graph, 4, 1, 8, 0);
	connect(&graph, 4, 2, 7, 0);
	connect(&graph, 3, 4, 9, 0);
	showGraph(&graph); printf("\n");
	showList(&graph); printf("\n");

	wide(&graph, 3);

	return 0;

}

int dijex() {

	GRAPH graph = init();

	insertGraph(&graph, 1);
	insertGraph(&graph, 2);
	insertGraph(&graph, 3);
	insertGraph(&graph, 4);
	insertGraph(&graph, 5);

	connect(&graph, 3, 5, 9, 0);
	connect(&graph, 4, 1, 8, 0);
	connect(&graph, 4, 2, 7, 0);
	connect(&graph, 3, 4, 9, 0);
	showGraph(&graph); printf("\n");
	showList(&graph); printf("\n");

	dijkstra(&graph, get(&graph, 3));

	return 0;

}


int main() { return dijex(); }
