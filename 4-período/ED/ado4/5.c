#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	struct node* next;
	struct node* prev;
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

void reinit(LIST* l) {
	*l = init();
}

void insert(LIST* l, int val) {

	NODE* new = malloc(sizeof(NODE));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;

	if (l->begin == NULL) {
		l->begin = new;
		l->begin->next = l->begin;
		l->begin->prev = l->begin;
		return;
	}

	new->next = l->begin;
	new->prev = l->begin->prev;
	l->begin->prev->next = new;
	l->begin->prev = new;

}

void delete(LIST* l, int val) {

	if (l->begin == NULL) return;
	if (l->begin->val == val) {
		l->begin->next->prev = l->begin->prev;
		l->begin->prev->next = l->begin->next;
		l->begin = l->begin->next;
		return;
	}

	NODE* n = l->begin;
	do {
		if (n->val == val) {
			n->prev->next = n->next;
			n->next->prev = n->prev;
			break;	
		}
		n = n->next;
	} while (n != l->begin);

}

void insertSort(LIST* l, int val) {

	NODE* new = malloc(sizeof(NODE));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;

	if (l->begin == NULL) {
		l->begin = new;
		l->begin->next = l->begin;
		l->begin->prev = l->begin;
		return;
	}

	if (l->begin->prev->val < val) {
		new->next = l->begin;
		new->prev = l->begin->prev;
		l->begin->prev->next = new;
		l->begin->prev = new;
		return;
	}

	NODE* n = l->begin;
	do {
		if (n->val > val) {
			new->next = n;
			new->prev = n->prev;
			n->prev->next = new;
			n->prev = new;
			break;	
		}
		n = n->next;
	} while (n != l->begin);

	if (l->begin->val > l->begin->prev->val) l->begin = l->begin->prev;

}

NODE* find(LIST* l, int val) {

	NODE* n = l->begin;
	do {
		if (n->val == val) return n;
		n = n->next;
	} while (n != l->begin);
	return NULL;

}

void swap(LIST* l, int val, int new) {

	NODE* n = l->begin;
	do {
		if (n->val == val) { 
			n->val = new;
			return;
		}
		n = n->next;
	} while (n != l->begin);

}

void show(LIST* l) {

	if (l->begin == NULL) return;

	NODE* n = l->begin;
	do {
		printf("%d ", n->val);
		n = n->next;
	} while (n != l->begin);
	printf("\n");

}


int main() {

	LIST list = init();
	insert(&list, 3);
	insert(&list, 2);
	insert(&list, 5);
	insert(&list, 4);
	insert(&list, 1);
	printf("list: "); show(&list);

	delete(&list, 3);
	printf("list: "); show(&list);

	NODE* n = find(&list, 4);
	printf("node: %d\n", n->val);

	swap(&list, 4, 8);
	printf("nval: "); show(&list);

	reinit(&list);
	printf("reinit: "); show(&list); printf("\n");

}
