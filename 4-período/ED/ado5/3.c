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

int palin(char* string) {

	STACK s = init();
	int l = strlen(string);
	int w = l / 2;

	for (int i = w; i > 0; i--) put(&s, *(string+i-1));

	if (l % 2 == 0) { for (l; l >= w+1; l--) if (pop(&s).val != *(string+l-1)) return 0; }
	else { for (l; l > w+1; l--) if (pop(&s).val != *(string+l-1)) return 0; }

	return 1;

}


int main() { printf("%s\n", palin("123321") ? "TRUE" : "FALSE"); }
