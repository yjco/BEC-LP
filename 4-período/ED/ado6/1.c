#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node* next;
} NODE;

typedef struct query {
	NODE* begin;
} QUERY;


QUERY init() {
	QUERY* q = malloc(sizeof(QUERY));
	q->begin = NULL;
	return *q;
}

void append(QUERY* q, int val) {

	NODE* n = malloc(sizeof(NODE));
	n->next = NULL;
	n->val = val;
	
	if (q->begin == NULL) { 
		q->begin = n;
		return;
	}

	NODE* m = q->begin;
	while (m->next != NULL) m = m->next;
	m->next = n;

}

NODE pop(QUERY* q) {
	NODE* n = q->begin;
	q->begin = q->begin->next;
	return *n;
}

void show(QUERY* q) {
	NODE* n = q->begin;
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}


int main() {

	QUERY query = init();
	append(&query, 5);
	append(&query, 8);
	append(&query, 1);
	append(&query, 0);
	append(&query, 3);

	show(&query);
	printf("%d\n", pop(&query).val);
	show(&query);

}
