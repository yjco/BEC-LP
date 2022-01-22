#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int val;
	struct node* left;
	struct node* right;
} NODE;

typedef struct tree {
	NODE* root;
} TREE;


TREE init() {
	TREE* t = (TREE*)malloc(sizeof(TREE));
	t->root = NULL;
	return *t;
}

void saux(NODE* n) {
	printf("(");
	if (n != NULL) {
		printf("%d", n->val);
		saux(n->left);
		saux(n->right);
	}
	printf(")");
}

void show(TREE* t) { saux(t->root); printf("\n"); }

int haux(NODE* n, int h) {
	if (n == NULL) return h;
	h++;
	int hl = haux(n->left, h);
	int hr = haux(n->right, h);
	return (hl > hr) ? hl : hr;
}

int height(TREE* t) { return haux(t->root, 0); }

NODE* rleft(NODE* n) {
	NODE* m = n->left;
	n->left = m->right;
	m->right = n;
	return m;
}

NODE* rright(NODE* n) {
	NODE* m = n->right;
	n->right = m->left;
	m->left = n;
	return m;
}

NODE* drleft(NODE* n) {
	n->left = rright(n->left);
	return rleft(n);
}

NODE* drright(NODE* n) {
	n->right = rleft(n->right);
	return rright(n);
}

NODE* iaux(NODE* n, NODE* m) {
	if (n == NULL) return m;
	if (m->val <= n->val) { n->left = iaux(n->left, m); } 
	else { n->right = iaux(n->right, m); }
	switch (haux(n->left, 0) - haux(n->right, 0)) {
		case 0 : case 1 : case -1 : return n;
		case -2 : return (n->right->right == NULL) ? drright(n) : rright(n);
		case 2 : return (n->left->left == NULL) ? drleft(n) : rleft(n);
	}
}

void insert(TREE* t, int i) {
	NODE* a = malloc(sizeof(NODE));
	a->left = malloc(sizeof(NODE));
	a->right = malloc(sizeof(NODE));
	a->left = NULL;
	a->right = NULL;
	a->val = i;
	t->root = iaux(t->root, a);
}

void sort(int list[], int s, int* store) {

	TREE tree = init();
	for (int i = 0; i < s; i++) insert(&tree, list[i]);

	int sorted[s];
	int i = 0, j = 0;
	NODE* copy = tree.root;
	NODE* aux = malloc(s * sizeof(NODE));
	while (1) {
		if (copy != NULL) {
			aux[i++] = *copy;
			copy = copy->left;
		} else if (j != s) {
			copy = &aux[--i];
			sorted[j++] = copy->val;
			copy = copy->right;
		} else break;
	}

	memcpy(store, sorted, s*4);

}

int main() {
	int list[5] = { 5, 2, 3, 4, 1 };
	int* sorted = malloc(sizeof(int) * 5);
	sort(list, 5, sorted);
	for (int i = 0; i < 5; i++) printf("%d ", sorted[i]);
	printf("\n");
}
