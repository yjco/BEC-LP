#include <stdio.h>
#include <stdlib.h>


typedef struct key {
	int value;
	struct key* next;
} KEY;

typedef struct list {
	KEY* head;
} LIST;


void init(LIST* l) {
	l -> head = malloc(sizeof(KEY));
	l -> head = NULL;
}

void show(LIST* l) {
	printf("List: ");
	KEY* k = l -> head;
	while (k != NULL) {
		printf("%d ", k -> value);
		k = k -> next;
	}
	printf("\n");
}

void nsrt(LIST* l, int i) {

	KEY* a = malloc(sizeof(KEY));
	a -> value = i;
	a -> next = NULL;

	KEY* k = l -> head;
	if (k == NULL) {
		l -> head = a;
		return;
	}

	while (k -> next != NULL) k = k -> next;
	k -> next = a;

}

KEY* find(LIST* l, int v) {
	KEY* k = l -> head;
	do {
		if (k -> value == v) return k;
		k = k -> next;
	} while (k != l -> head);
	return NULL;
}

int fpos(LIST* l, int v) {
	int i = 0;
	KEY* k = l -> head;
	do {
		if (k -> value == v) return i;
		k = k -> next;
		i++;
	} while (k != l -> head);
	return -1;
}


int main() {

	LIST list;
	init(&list);

	show(&list);

	nsrt(&list, 0);
	nsrt(&list, 1);
	nsrt(&list, 2);
	nsrt(&list, 3);
	nsrt(&list, 4);
	nsrt(&list, 5);

	show(&list);

	printf("O valor %d na lista está na posição: %d\n", 
		find(&list, 4) -> value, fpos(&list, 4));

}
