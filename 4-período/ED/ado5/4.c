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
		printf("%c ", srev(n->down));
		return n->val;
	}
}

void show(STACK* s, int rev) {
	NODE* n = s->top;
	if (n == NULL) {
		printf("\n");
		return;
	}
	if (rev) printf("%c ", srev(s->top));
	else {
		while (n != NULL) {
			printf("%c ", n->val);
			n = n->down;
		}
	}
	printf("\n");
}

void intopos(char* in, char* pos) {

	int j = 0;
	STACK oprs = init();
	for (int i = -1; i < (int)strlen(in); i++) {
		if ((in[i] < 'a' || in[i] > 'z') && (in[i] < 'A' || in[i] > 'Z') && (in[i] < '0' || in[i] > '9')) 
			put(&oprs, in[i]);
		else 
			pos[j++] = in[i];
	}

	while (oprs.top != NULL) pos[j++] = pop(&oprs).val;

}


int main() { 

	char* in = "A+B*C";
	char pos[strlen(in)];

	intopos(in, pos);
	printf("%s\n", pos);

	return 0;

}
