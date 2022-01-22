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

void show(LIST* list) {
	for (NODE* n = list->begin; n != NULL; n = n->next) printf("%d ", n->val);
	printf("\n");
}


int main() {

	LIST list = init();
	insert(&list, 3);
	insert(&list, 2);
	insert(&list, 5);
	insert(&list, 4);
	insert(&list, 1);
	show(&list);

}
