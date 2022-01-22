#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node* next;
} NODE;

typedef struct query {
	NODE* head;
} QUERY;


QUERY init() {
	QUERY* q = malloc(sizeof(QUERY));
	q->head = NULL;
	return *q;
}

void add(QUERY* q, int val) {

	NODE* m = malloc(sizeof(NODE));
	m->next = q->head;
	m->val = val;

	if (q->head == NULL) {
		m->next = m;
		q->head = m;
		return;
	}

	NODE* n = q->head;
	while (n->next != q->head) n = n->next;
	n->next = m;

}

void show(QUERY* q) {
	if (q->head == NULL) return;
	NODE* n = q->head;
	do {
		printf("%d ", n->val);
		n = n->next;
	} while (n != q->head);
	printf("\n");
}

void fura(QUERY* q, int val) {

	NODE* m = malloc(sizeof(NODE));
	m->next = q->head->next;
	m->val = q->head->val;

	q->head->next = m;
	q->head->val = val;

}


int main() {

	QUERY query = init();

	add(&query, 10);
	show(&query);
	add(&query, 20);
	show(&query);
	add(&query, 30);
	show(&query);

	fura(&query, 55);
	show(&query);

	return 0;

}
