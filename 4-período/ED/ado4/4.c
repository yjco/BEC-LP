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

int contains(LIST* l, int val) {

	if (l->begin == NULL) return 0;

	NODE* n = l->begin;
	do {
		if (n->val == val) return 1;
		n = n->next;
	} while (n != l->begin);
	return 0;

}

LIST lunion(LIST* l, LIST* r, int unique) {

	LIST u = init();
	if (l == r) return u;

	NODE* n = l->begin;
	do {
		if (unique && contains(&u, n->val)) { 
			n = n->next;
			continue;
		}
		insert(&u, n->val);
		n = n->next;
	} while (n != l->begin);

	n = r->begin;
	do {
		if (unique && contains(&u, n->val)) { 
			n = n->next;
			continue;
		}
		insert(&u, n->val);
		n = n->next;
	} while (n != r->begin);

	return u;

}

LIST linter(LIST* l, LIST* r) {

	LIST u = init();
	if (l == r) return u;

	NODE* n = l->begin;
	do {
		if (contains(r, n->val)) insert(&u, n->val);
		n = n->next;
	} while (n != l->begin);

	return u;

}

void show(LIST* l) {

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

	LIST rist = init();
	insert(&rist, 6);
	insert(&rist, 4);
	insert(&rist, 9);
	insert(&rist, 8);
	insert(&rist, 2);
	printf("rist: "); show(&rist);

	LIST u = lunion(&list, &rist, 1);
	printf("union: "); show(&u);

	u = linter(&list, &rist);
	printf("inter: "); show(&u);

}
