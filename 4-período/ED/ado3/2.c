#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	struct node* next;
	int val;
} NODE;

typedef struct list {
	NODE* begin;
} LIST;


LIST init() {
	LIST* l = malloc(sizeof(LIST));
	l->begin = NULL;
	return *l;
}

void insert(LIST* l, int val) {

	NODE* new = malloc(sizeof(NODE));
	new->val = val;
	new->next = NULL;

	if (l->begin == NULL) {
		l->begin = new;
		return;
	}

	if (l->begin->val > val) {
		NODE* a = l->begin;
		l->begin = new;
		l->begin->next = a;
		return;
	}

	NODE* p = l->begin;
	NODE* n = l->begin->next;
	while (n != NULL) {
		if (n->val > val) {
			p->next = new;
			new->next = n;
		}
		p = n;
		n = n->next;
	}
	if (new->next == NULL) p->next = new;

}

int cmp(LIST* l, LIST* t) {

	NODE* n = l->begin;
	NODE* m = t->begin; 
	
	while (n != NULL && m != NULL) {
		if (n->val != m->val) return 0;
		n = n->next;
		m = m->next;
	}

	if (n != NULL || m != NULL) return 0;

	return 1;

}

void show(LIST* list) {
	for (NODE* n = list->begin; n != NULL; n = n->next) printf("%d ", n->val);
	printf("\n");
}


int main() {

	LIST alist = init();
	insert(&alist, 1);
	insert(&alist, 2);
	insert(&alist, 4);
	insert(&alist, 3);
	printf("A: ");
	show(&alist);

	LIST blist = init();
	insert(&blist, 1);
	insert(&blist, 2);
	insert(&blist, 4);
	insert(&blist, 5);
	printf("B: ");
	show(&blist);

	printf("A %c= B\n", (cmp(&alist, &blist)) ? '=' : '!');

}
