#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* SEQ;
int found;

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
		printf(" %c  ", m->val);
		i++;
	}
	printf("\n  +-");

	while (i-- != 0) printf("----");
	printf("\n");

	for (NODE* m = g->begin; m != NULL; m = m->next) {
		i++;
		printf("%c | ", m->val);
		for (int j = 0; j < g->n; j++) printf("%2d  ", *(*(g->matrix+i)+j));
		printf("\n");
	}

}

void showColors(GRAPH* g, int* colors, int* distance) {

	for (NODE* m = g->begin; m != NULL; m = m->next) printf("%d ", m->val);
	printf("\n");

	for (int i = 0; i < g->n; i++) printf("%d ", *(colors+i));
	printf("\n");

	if (distance == NULL) return;
	for (int i = 0; i < g->n; i++) printf("%c ", (*(distance+i) == -1) ? '.' : *(distance+i) + '0');
	printf("\n");

}

void visit(GRAPH* g, int n, int* colors, int* distance) {


	int fn = find(g, n);
	(*(colors+fn))++;
	(*(distance+fn))++;

	//showColors(g, colors, distance); printf("\n");

	int i = 0;
	int* aux = (int*)malloc(sizeof(int) * g->n);
	for (NODE* m = g->begin; m != NULL; m = m->next) {
		if (connected(g, n, m->val) && *(colors+find(g, m->val)) == 0) {
			*(aux+(i++)) = m->val;
			*(distance+find(g, m->val)) = *(distance+fn);
			//showColors(g, colors, distance); printf("\n");
		}
	}

	for (int j = 0; j < i; j++) visit(g, *(aux+j), colors, distance);
	if (++(*(colors+fn)) == 2) *(SEQ+(found++)) = n;

}

void wide(GRAPH* g, int begin) {

	if (g->begin == NULL) return;

	int* colors = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(colors+i) = 0;

	int* distance = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(distance+i) = -1;

	*(SEQ+(found++)) = begin;

	//showColors(g, colors, distance); printf("\n");
	visit(g, begin, colors, distance);
	//showColors(g, colors, distance);

	free(colors);

}

void dvisit(GRAPH* g, int n, int* colors) {

	*(SEQ+(found++)) = n;

	int fn = find(g, n);
	(*(colors+fn))++;

	//showColors(g, colors, NULL);
	//printf("\n");

	for (NODE* m = g->begin; m != NULL; m = m->next) {
		if (connected(g, n, m->val) && *(colors+find(g, m->val)) == 0) {
			dvisit(g, m->val, colors);
			//showColors(g, colors, NULL);
			//printf("\n");
		}
	}

	(*(colors+fn))++;

}

void depth(GRAPH* g, int begin) {

	if (g->begin == NULL) return;

	int* colors = (int*)malloc(sizeof(int) * g->n);
	for (int i = 0; i < g->n; i++) *(colors+i) = 0;

	//showColors(g, colors, NULL); printf("\n");
	dvisit(g, begin, colors);
	//showColors(g, colors, NULL);

	free(colors);

}


int main() {

	GRAPH graph = init();

	insert(&graph, 'A');
	insert(&graph, 'B');
	insert(&graph, 'C');
	insert(&graph, 'D');
	insert(&graph, 'E');
	insert(&graph, 'F');
	insert(&graph, 'G');
	insert(&graph, 'H');

	connect(&graph, 'A', 'B', 3, 1);
	connect(&graph, 'A', 'C', 5, 1);
	connect(&graph, 'A', 'D', 2, 1);
	connect(&graph, 'A', 'H', 10, 1);

	connect(&graph, 'B', 'C', 5, 1);
	connect(&graph, 'B', 'D', 8, 1);
	connect(&graph, 'B', 'G', 6, 1);

	connect(&graph, 'C', 'E', 1, 1);
	connect(&graph, 'C', 'G', 9, 1);
	connect(&graph, 'C', 'F', 7, 1);

	connect(&graph, 'D', 'E', 12, 1);
	connect(&graph, 'D', 'H', 14, 1);

	connect(&graph, 'E', 'G', 15, 1);

	connect(&graph, 'F', 'H', 9, 1);

	connect(&graph, 'G', 'H', 3, 1);

	show(&graph); printf("\n");

	SEQ = (char*)malloc(sizeof(char) * 9);
	printf("Combinações encontradas:\n");
	for (NODE* n = graph.begin; n != NULL; n = n->next) {

		found = 0;
		depth(&graph, n->val);
		*(SEQ+found) = '\0';
		printf("P: %s\n", SEQ);

		found = 0;
		wide(&graph, n->val);
		*(SEQ+(--found)) = '\0';
		printf("L: %s\n", SEQ);

		printf("-----------\n");

	}

	return 0;

}
