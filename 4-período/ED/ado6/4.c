#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int val;
	struct node* next;
} NODE;

typedef struct list {
	NODE* head;
} LIST;


LIST init() {
	LIST* l = malloc(sizeof(LIST));
	l->head = NULL;
	return *l;
}

void add(LIST* l, int val, int top) {

	NODE* m = malloc(sizeof(NODE));
	m->next = NULL;
	m->val = val;

	if (l->head == NULL) {
		l->head = m;
		return;
	}

	NODE* n = l->head;

	if (top) {
		while (n->next != NULL) n = n->next;
		n->next = m;
	} else {
		m->next = l->head;
		l->head = m;
	}

}

void del(LIST* l, int top) {

	if (l->head == NULL) return;
	if (l->head->next == NULL) {
		l->head = NULL;
		return;
	}

	if (top) {
		NODE* n = l->head;
		while (n->next->next != NULL) n = n->next;
		n->next = NULL;
	} else {
		l->head = l->head->next;
	}

}

void show(LIST* l) {
	NODE* n = l->head;
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}


int main() { 

	LIST deck = init();
	add(&deck, 1, 1);
	add(&deck, 2, 1);
	add(&deck, 3, 1);
	show(&deck);

	add(&deck, 0, 0);
	show(&deck);

	del(&deck, 1);
	show(&deck);

	del(&deck, 0);
	show(&deck);

}
