#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int val;
	struct node* next;
} NODE;

typedef struct graph {
	int n;
	NODE* begin;
	int** matrix;
} GRAPH;


GRAPH init() {

	GRAPH* g = (GRAPH*)malloc(sizeof(GRAPH));
	g->matrix = NULL;
	g->begin = NULL;
	g->n = 0;

	return *g;

}

void insert(GRAPH* g, int val) {

	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->next = NULL;
	n->val = val;

	if (g->begin == NULL) {
		g->begin = n;
		g->matrix = (int**)malloc(sizeof(int*));
		*(g->matrix) = 0;
		g->n++;
	} else {
		NODE* m = g->begin;
		while (m->next != NULL) {
			if (m->val == val) return;
			m = m->next;
		}
		m->next = (NODE*)malloc(sizeof(NODE));
		*(m->next) = *n;

		g->n++;
		for (int i = 0; i < g->n; i++) *(g->matrix+i) = (int*)malloc(sizeof(int) * g->n);
		for (int i = 0; i < g->n; i++) {
			*(*((g->matrix)+i)+g->n-1) = 0;
			*(*((g->matrix)+g->n-1)+i) = 0;
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
	if (both) *(*((g->matrix)+n2)+n1) = weight;

}

void show(GRAPH* g) {

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

void showColors(GRAPH* g, int* colors) {
	for (NODE* m = g->begin; m != NULL; m = m->next) printf("%d ", m->val); printf("\n");
	for (int i = 0; i < g->n; i++) printf("%d ", *(colors+i)); printf("\n");
}

void visit(GRAPH* g, int n, int* colors) {

	int fn = find(g, n);
	(*(colors+fn))++;

	//showColors(g, colors); printf("\n");

	for (NODE* m = g->begin; m != NULL; m = m->next) {
		if (connected(g, n, m->val) && *(colors+find(g, m->val)) == 0) {
			visit(g, m->val, colors);
			//showColors(g, colors); printf("\n");
		}
	}

	(*(colors+fn))++;

}

void depth(GRAPH* g, int begin) {

	if (g->begin == NULL) return;

	int* colors = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(colors+i) = 0;

	//showColors(g, colors); printf("\n");
	visit(g, begin, colors);
	//showColors(g, colors);

	free(colors);

}

void topoVisit(GRAPH* g, int n, int* colors, int* sorted, int index) {

	sorted[index++] = n;
	int fn = find(g, n);
	(*(colors+fn))++;

	for (NODE* m = g->begin; m != NULL; m = m->next) {
		if (connected(g, n, m->val) && *(colors+find(g, m->val)) == 0) {
			topoVisit(g, m->val, colors, sorted, index);
		}
	}

	(*(colors+fn))++;

}

void topoSort(GRAPH* g, int begin, int* sorted) {

	if (g->begin == NULL) return;

	int* colors = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(colors+i) = 0;

	topoVisit(g, begin, colors, sorted, 0);

	free(colors);

}


int main() {

	GRAPH graph = init();

	insert(&graph, 1);
	insert(&graph, 2);
	insert(&graph, 3);
	insert(&graph, 4);
	insert(&graph, 5);

	connect(&graph, 3, 4, 9, 0);
	connect(&graph, 3, 5, 9, 0);
	connect(&graph, 4, 1, 8, 0);
	connect(&graph, 4, 2, 7, 0);
	show(&graph); printf("\n");

	int* sorted = (int*)malloc(sizeof(int) * graph.n);
	topoSort(&graph, 3, sorted);
	for (int i = 0; i < graph.n; i++) printf("%d ", sorted[i]);
	printf("\n");

	return 0;

}
