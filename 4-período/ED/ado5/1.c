#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	char c;
	struct node* down;
} NODE;

typedef struct stack {
	NODE* top;
} STACK;


void init(STACK* s) {
	s->top = malloc(sizeof(NODE));
	s->top = NULL;
}

void put(STACK* s, char c) {
	NODE* i = malloc(sizeof(NODE));
	i->c = c;
	i->down = s->top;
	s->top = i;
}

NODE* pop(STACK* s) {
	NODE* i = s->top->down;
	s->top = s->top->down;
	return i;
}

char srev(NODE* i) {
	if (i -> down == NULL) {
		return i->c;
	} else {
		printf("%c ", srev(i->down));
		return i->c;
	}
}

void show(STACK* s, int rev) {
	NODE* i = s->top;
	if (i == NULL) {
		printf("\n");
		return;
	}
	if (rev) {
		printf("%c ", srev(s->top));
	} else {
		while (i != NULL) {
			printf("%c ", i->c);
			i = i->down;
		}
	}
	printf("\n");
}

int format(char* string) {

	STACK stack;
	init(&stack);

	for (char c = *string; c != '\0'; c = *(++string)) { 

		if (c != '(' && c != ')' &&
		    c != '[' && c != ']' &&
		    c != '{' && c != '}' ) 
			continue;

		if (stack.top != NULL) {
			switch (stack.top->c) {
				case '(' :
					if (c == ']' || c == '}') return 0;
					else if (c == ')') pop(&stack);
					else put(&stack, c);
					continue;
				case '[' :
					if (c == ')' || c == '}') return 0;
					else if (c == ']') pop(&stack);
					else put(&stack, c);
					continue;
				case '{' :
					if (c == ']' || c == ')') return 0;
					else if (c == '}') pop(&stack);
					else put(&stack, c);
					continue;
				default :
					return 0;
			}
		}
		if (c == '(' || c == '[' || c == '{') put(&stack, c);

	}

	return 1;

}


int main() {

	char* string = "({{}])";
	printf("%s\n", (format(string)) ? "TRUE" : "FALSE");

}
