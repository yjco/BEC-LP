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
	ITEM* i = s -> top -> down;
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


int main() {

	STACK stack;
	init(&stack);

	char c;
	while (1) {
		printf(": ");
		show(&stack, 1);
		scanf("%c", &c);
		getchar();
		if (stack.top != NULL) {
			switch ((stack.top) -> c) {
				case '(' :
					if (c == ']' || c == '}') {
						printf("Mal formada! Ignorando...\n");
					} else if (c == ')') {
						pop(&stack);
					} else {
						put(&stack, c);
					}
					continue;
				case '[' :
					if (c == ')' || c == '}') {
						printf("Mal formada! Ignorando...\n");
						continue;
					} else if (c == ']') {
						pop(&stack);
					} else {
						put(&stack, c);
					}
					continue;
				case '{' :
					if (c == ']' || c == ')') {
						printf("Mal formada! Ignorando...\n");
						continue;
					} else if (c == '}') {
						pop(&stack);
					} else {
						put(&stack, c);
					}
					continue;
				default :
					printf("Mal formada! Ignorando...");
					continue;
			}
		}
		if (c == '(' || c == '[' || c == '{') put(&stack, c);
		else if (c == 'E') exit(0);
	}

	return 0;

}
