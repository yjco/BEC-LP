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
		//printf("%p %p\n", n, l->begin);
	} while (n != l->begin);
	printf("\n");

}

void delete(LIST* l, int val) {

	if (l->begin->val == val) {
		l->begin = l->begin->next;
		return;
	}

	NODE* n = l->begin;
	do {
		if (n->next->val == val) {
			n->next = n->next->next;
			return;
		}
		n = n->next;
	} while (n != l->begin);

}

int josephus(LIST* l, int k) {

	int c;
	NODE* n = l->begin;
	while (n != n->next) {
		c = k;
		while (c-- != 0) n = n->next;
		delete(l, n->val);
	}
	return n->val;

}


int main() {

	LIST l = init();
	insert(&l, 10);
	insert(&l, 30);
	insert(&l, 20);

	show(&l);
	printf("%d\n", josephus(&l, 40));

}
