#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node* next;
} NODE;

typedef struct list {
	NODE* begin;
} LIST;


LIST init() {
	LIST* l = (LIST*)malloc(sizeof(LIST));
	l->begin = NULL;
	return *l;
}

void insert(LIST* l, int val) {

	NODE* m = (NODE*)malloc(sizeof(NODE));
	m->next = NULL;
	m->val = val;

	if (l->begin == NULL) {
		l->begin = m;
		l->begin->next = l->begin;
		return;
	}

	NODE* n = l->begin;
	while (n->next != l->begin) {
		if (n->next->val > val) {
			m->next = n->next;
			n->next = m;
			return;
		}
		n = n->next;
	}

	n->next = m;
	n->next->next = l->begin;

}

void show(LIST* l) {

	NODE* n = l->begin;	
	do { 
		printf("%d ", n->val);
		n = n->next;
	} while (n != l->begin);
	printf("\n");

}

int same(LIST* l, LIST* r) {

	if (l == r) return 0;

	NODE* n = l->begin;
	NODE* m = r->begin;
	do {
		if (n->val != m->val) return 0;
		n = n->next;
		m = m->next;
	} while (n != l->begin && m != r->begin);
	return (n == l->begin && m == r->begin) ? 1 : 0;

}


int main() {

	LIST l = init();
	insert(&l, 10);
	insert(&l, 30);
	insert(&l, 20);

	LIST r = init();
	insert(&r, 10);
	insert(&r, 30);
	insert(&r, 20);

	printf("%d\n", same(&l, &r));

}
