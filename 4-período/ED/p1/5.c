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

typedef struct queue {
	STACK* frnt;
	STACK* back;
} QUEUE;

void qinit(QUEUE* q) {
	q -> frnt = malloc(sizeof(STACK));
	q -> back = malloc(sizeof(STACK));
}

void qshow(QUEUE* q) {
	printf("Front: ");
	show(q -> frnt, 0);
	printf("Back: ");
	show(q -> back, 0);
}

void enqueue(QUEUE* q, char c) {

	if (q -> frnt -> top == NULL) {
		put(q -> frnt, c);
		put(q -> back, c);
		return;
	}

	put(q -> back, c);

	STACK s;
	init(&s);

	s = *(q -> back);
	*(q -> frnt) = invert(&s);

}

void dequeue(QUEUE* q) {

	if (q -> frnt -> top == NULL) return;

	pop(q -> frnt);

	STACK s;
	init(&s);

	s = *(q -> frnt);
	*(q -> back) = invert(&s);

}

int main() {

	QUEUE queue;
	qinit(&queue);

	enqueue(&queue, 'a');
	enqueue(&queue, 'b');
	enqueue(&queue, 'c');

	qshow(&queue);
	dequeue(&queue);
	qshow(&queue);

	return 0;

}
