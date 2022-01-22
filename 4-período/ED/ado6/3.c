#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	char val;
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

void put(STACK* s, char val) {
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

NODE delete(STACK* s) {

	STACK r = init();

	while (s->top != NULL) put(&r, pop(s).val);
	NODE n = pop(&r);
	while (r.top != NULL) put(s, pop(&r).val);

	return n;

}


int main() { 
	
	STACK query = init();

	// Operação de adicioar é igual a da pilha
	put(&query, 1);
	put(&query, 2);
	put(&query, 3);
	show(&query, 1);

	// Operação de remoção
	delete(&query);
	show(&query, 1);

}
