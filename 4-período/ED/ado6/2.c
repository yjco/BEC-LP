#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int i;
	struct node* next;
} NODE;

typedef struct list {
	int set;
	NODE* head;
} LIST;


void init(LIST* l) {
	l -> head = malloc(sizeof(NODE));
	l -> head -> next = l -> head;
	l -> set = 0;
}

void show(LIST* l) {
	if (l -> set == 0) return;
	NODE* n = l -> head;
	while (n -> next != l -> head) {
		printf("%d ", n -> i);
		n = n -> next;
	}
	printf("%d\n", n -> i);
}

void fura(LIST* l, int i) {

	NODE* m = malloc(sizeof(NODE));
	m -> i = i;
	m -> next = l -> head;

	NODE* n = l -> head;
	while (n -> next != l -> head) n = n -> next;
	n -> next = m;
	l -> head = m;

}

void add(LIST* l, int i) {
	NODE* m = malloc(sizeof(NODE));
	m -> i = i;
	m -> next = l -> head;

	if (l -> set == 0) {
		l -> set = 1;
		fura(l, i);
		l -> head -> next = l -> head;
		return;
	}

	NODE* n = l -> head;
	while (n -> next != l -> head) n = n -> next;
	n -> next = m;
}

int main() {

	LIST list;
	init(&list);

	show(&list);
	add(&list, 10);
	show(&list);
	add(&list, 20);
	show(&list);
	add(&list, 30);
	show(&list);

	fura(&list, 55);
	show(&list);

	return 0;

}
