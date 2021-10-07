#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct item {
	char c;
	struct item* down;
} ITEM;

typedef struct stack {
	ITEM* top;
} STACK;


void init(STACK* s) {
	s -> top = malloc(sizeof(ITEM));
	s -> top = NULL;
}

void put(STACK* s, char c) {
	ITEM* i = malloc(sizeof(ITEM));
	i -> c = c;
	i -> down = s -> top;
	s -> top = i;
}

ITEM* pop(STACK* s) {
	ITEM* i = s -> top;
	s -> top = s -> top -> down;
	return i;
}

char srev(ITEM* i) {
	if (i -> down == NULL) {
		return i -> c;
	} else {
		printf("%c ", srev(i -> down));
		return i -> c;
	}
}

void show(STACK* s, int rev) {
	ITEM* i = s -> top;
	if (i == NULL) {
		printf("\n");
		return;
	}
	if (rev) {
		printf("%c ", srev(s -> top));
	} else {
		while (i != NULL) {
			printf("%c ", i -> c);
			i = i -> down;
		}
	}
	printf("\n");
}

STACK invert(STACK* s) {

	STACK stack;
	init(&stack);

	while (s -> top != NULL) put(&stack, pop(s) -> c);
	return stack;

}

int palin(STACK* s, STACK* k) {
	char c, h;
	while (s -> top != NULL && k -> top != NULL) if (pop(s) -> c != pop(k) -> c) return 0;
	return (s -> top != NULL || k -> top != NULL) ? 0 : 1;
}


int main() {

	STACK copy;
	STACK stack;
	init(&stack);

	put(&stack, 'a');
	put(&stack, 'b');
	put(&stack, 'c');
	put(&stack, 'b');
	put(&stack, 'a');

	show(&stack, 0);
	copy = stack;

	STACK kcats = invert(&copy);

	printf("%s palindromo\n", palin(&stack, &kcats) ? "É" : "Não é");

}
