#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int srev(NODE* n) {
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

int T(int x[], int n) {
  if (n == 0) return 0;
  if (x[n] > 0) return x[n] + T(x, n-1);
  else return T(x, n-1);
}


int main() { 

	STACK s = init();
	int x[5] = { 1, 2, -3, 4, 5 };
	int n = 5;
	
	for (int i = n-1; i > 0; i--) put(&s, x[i]);

	int i;
	int sum = 0;
	while (s.top != NULL) {
		i = pop(&s).val;
		if (i > 0) sum += i;
	}

	printf("stack: %d\n", sum);
	printf("T: %d\n", T(x, 4));

}
