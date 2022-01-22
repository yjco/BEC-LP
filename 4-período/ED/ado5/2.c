#include <stdio.h>
#include <stdlib.h>


/* STACK */

typedef struct node {
	int val;
	struct node* down;
} NODE;

typedef struct stack {
	struct node* top;
} STACK;


STACK init() {
	STACK* s = malloc(sizeof(STACK));
	s->top = NULL;
	return *s;
}

void put(STACK* s, int val) {
	NODE* n = malloc(sizeof(NODE));
	n->val = val;
	n->down = s->top;
	s->top = n;
}

NODE pop(STACK* s) {
	NODE* n = s->top;
	s->top = s->top->down;
	return *n;
}

char srev(NODE* n) {
	if (n->down == NULL) return n->val;
	else {
		printf("%d ", srev(n->down));
		return n->val;
	}
}

void show(STACK* s, int rev) {
	NODE* n = s->top;
	if (n == NULL) {
		printf("\n");
		return;
	}
	if (rev) printf("%d ", srev(s->top));
	else {
		while (n != NULL) {
			printf("%d ", n->val);
			n = n->down;
		}
	}
	printf("\n");
}

/* STACK */

/* LIST */

typedef struct lode {
	int val;
	struct lode* next;
} LODE;

typedef struct list {
	LODE* begin;
} LIST;

LIST linit() {
	LIST* l = malloc(sizeof(LIST));
	l->begin = NULL;
	return *l;
}

void append(LIST* l, int val) {

	LODE* n = malloc(sizeof(LODE));
	n->val = val;
	n->next = NULL;

	if (l->begin == NULL) {
		l->begin = n;
		return;
	}

	LODE* m = l->begin;
	while (m->next != NULL) m = m->next;
	m->next = n;

}

void lshow(LIST* l) {
	LODE* n = l->begin;
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}

/* LIST */


void stack_remains(STACK* s, int val) {
	if (val == 0) return;
	put(s, val % 2);
	stack_remains(s, val / 2);
}

LIST dtob(int dec) {
	STACK s = init();
	LIST l = linit();
	stack_remains(&s, dec);
	while (s.top != NULL) append(&l, pop(&s).val);
	return l;
}


int main() {
	LIST list = dtob(13);
	lshow(&list);
}
