#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef int bool;
typedef int TKEY;

typedef struct {
	TKEY key;
} REG;

typedef struct aux {
	REG reg;
	struct aux* next;
} ELEMENT;

typedef ELEMENT* PONT;

typedef struct {
	PONT begin;
} LIST;

void init(LIST* l) {
	l -> begin = NULL;
}

int size(LIST* l) {
	PONT end = l -> begin;
	int s = 0;
	while (end != NULL) {
		s++;
		end = end -> next;
	}
	return s;
}

void show(LIST* l) {
	PONT end = l -> begin;
	printf("List: ");
	while (end != NULL) {
		printf("%i ", end -> reg.key);
		end = end -> next;
	}
	printf("\n");
}

PONT seq(PONT curr, TKEY key) {
	if (curr == NULL) return NULL;
	if (curr -> reg.key == key) return curr;
	return seq(curr -> next, key);
}

bool insert(LIST* l, REG reg) {
	PONT p;
	p = (PONT) malloc(sizeof(ELEMENT));
	p -> reg = reg;

	if (l -> begin == NULL) {
		p -> next = NULL;
		l -> begin = p;
		return true;
	} else {
		PONT bef = NULL;
		PONT next = l -> begin;
		while (next != NULL) {
			if (next -> reg.key > reg.key) {
				p -> next = next;
				if (bef == NULL) {
					l -> begin = p;
				} else {
					bef -> next = p;
				}
				return true;
			}
			bef = next;
			next = next -> next;
		}
		p -> next = NULL;
		next = p;
		bef -> next = next;
	}

	return true;
}

int main() {

	REG r;
	LIST list;
	init(&list);

	printf("--------------------------------------\n");
	r.key = 3;
	insert(&list, r);
	r.key = 1;
	insert(&list, r);
	r.key = 2;
	insert(&list, r);
	show(&list);
	printf("Size: %d\n", size(&list));
	printf("--------------------------------------\n");
	printf("Address of 3: %p\n", &(seq((&list) -> begin, 3) -> reg.key));

	return 0;

}
