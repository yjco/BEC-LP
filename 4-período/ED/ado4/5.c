#include <stdio.h>
#include <stdlib.h>


typedef struct key {
	int value;
	struct key* next;
	struct key* prev;
} KEY;

typedef struct list {
	KEY* head;
	KEY* tail;
} LIST;


void init(LIST* l) {
	l -> head = malloc(sizeof(KEY));
	l -> tail = malloc(sizeof(KEY));

	l -> head -> value = 0;
	l -> head -> next = l -> tail;
	l -> head -> prev = l -> tail;

	l -> tail -> value = 0;
	l -> tail -> next = l -> head;
	l -> tail -> prev = l -> head;
}

void show(LIST* l) {
	KEY* k = l -> head;
	do {
		printf("%d ", k -> value);
		k = k -> next;
	} while (k != l -> head);
	printf("\n");
}

KEY* find(LIST* l, int v) {
	KEY* k = l -> head;
	do {
		if (k -> value == v) return k;
		k = k -> next;
	} while (k != l -> head);
	return NULL;
}

void nsrt(LIST* l, int v) {
	KEY* k = malloc(sizeof(KEY));
	k -> value = v;

	k -> prev = l -> tail;
	k -> next = l -> head;

	l -> head -> prev = k;
	l -> tail -> next = k;
	l -> tail = k;
}

void dlte(LIST* l, KEY* k) {
	KEY* q = l -> head;
	do {
		if (k == q) {
			q -> prev -> next = q -> next;
			q -> next -> prev = q -> prev;
			free(q);
			return;
		}
		q = q -> next;
	} while (q != l -> head);
}

void altr(LIST* l, int a, int v) {
	KEY* k = find(l, a);
	if (k != NULL) k -> value = v;
}

void rest(LIST* l) {
	KEY* k = l -> head -> next -> next;
	do {
		free(k -> prev);
		k = k -> next;

	} while(k != l -> head);
	free(k);
	init(l);
}


int main() {

	LIST list;
	init(&list);
	show(&list);

	nsrt(&list, 10);
	show(&list);

	nsrt(&list, 20);
	show(&list);

	KEY* key = find(&list, 10);
	printf("%d\n", key -> value);

	dlte(&list, key);
	show(&list);

	altr(&list, 0, 5);
	show(&list);

	rest(&list);
	show(&list);

	return 0;
}
