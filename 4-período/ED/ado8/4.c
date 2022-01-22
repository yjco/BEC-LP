/* RESPOSTA ERRADA */

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node* left;
	struct node* right;
	int fb;
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
	n->fb = haux(n->left, 0) - haux(n->right, 0);
	switch (n->fb) {
		case 0 : case 1 : case -1 : break;
		case -2 : n = (n->right->right == NULL) ? drright(n) : rright(n); break;
		case 2 : n = (n->left->left == NULL) ? drleft(n) : rleft(n); break;
	}
	return n;
}

void insert(TREE* t, int i) {
	NODE* a = malloc(sizeof(NODE));
	a->left = malloc(sizeof(NODE));
	a->right = malloc(sizeof(NODE));
	a->left = NULL;
	a->right = NULL;
	a->val = i;
	a->fb = 0;
	t->root = iaux(t->root, a);
}


int main() {

	TREE tree = init();
	
	insert(&tree, 20); show(&tree);
	insert(&tree, 10); show(&tree);
	insert(&tree, 5); show(&tree);
	insert(&tree, 30); show(&tree);
	insert(&tree, 25); show(&tree);
	insert(&tree, 27); show(&tree);
	insert(&tree, 28); show(&tree);
	insert(&tree, 32); show(&tree);
	insert(&tree, 14); show(&tree);
	insert(&tree, 39); show(&tree);
	insert(&tree, 6); show(&tree);

	return 0;

}
