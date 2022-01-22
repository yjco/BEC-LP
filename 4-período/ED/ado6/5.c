#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int p;
	char val;
	struct node* next;
} NODE;

typedef struct plist {
	NODE* head;
} PLIST;


PLIST init() {
	PLIST* pl = malloc(sizeof(PLIST));
	pl->head = NULL;
	return *pl;
}

void add(PLIST* pl, char val, int p) {

	NODE* n = malloc(sizeof(NODE));
	n->next = NULL;
	n->val = val;
	n->p = p;

	if (pl->head == NULL) {
		pl->head = n;
		return;
	}

	if (pl->head->p < p) {
		n->next = pl->head;
		pl->head = n;
		return;
	}

	NODE* m = pl->head;
	while (m->next != NULL) {
		if (m->next->p < p) {
			n->next = m->next;
			m->next = n;
			return;
		}
		m = m->next;
	}
	m->next = n;

}

void del(PLIST* pl) {
	if (pl->head == NULL) return;
	pl->head = pl->head->next;
}

void show(PLIST* pl) {
	NODE* n = pl->head;
	while (n != NULL) {
		printf("%c(%d) ", n->val, n->p);
		n = n->next;
	}
	printf("\n");
}


int main() {

	PLIST pl = init();

	add(&pl, 'a', 10);
	add(&pl, 'b', 15);
	add(&pl, 'c', 20);

	show(&pl);
	del(&pl);
	show(&pl);

	add(&pl, 'd', 30);
	show(&pl);

	add(&pl, 'e', 5);
	show(&pl);

	add(&pl, 'f', 12);
	show(&pl);

}
