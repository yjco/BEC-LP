#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node* left;
	struct node* right;
} NODE;

typedef struct tree {
	NODE* root;
} TREE;

int init(TREE* t) {
	t -> root = malloc(sizeof(NODE));
	t -> root = NULL;
}

void saux(NODE* n) {
	printf("(");
	if (n != NULL) {
		printf("%d", n -> val);
		saux(n -> left);
		saux(n -> right);
	}
	printf(")");
}

void show(TREE* t) {
	saux(t -> root);
	printf("\n");
}

NODE* iaux(NODE* n, NODE* m) {
	if (n == NULL) return m;
	if (m -> val <= n -> val) {
		n -> left = iaux(n -> left, m);
	} else {
		n -> right = iaux(n -> right, m);
	}
	return n;
}

void insert(TREE* t, int i) {
	NODE* a = malloc(sizeof(NODE));
	a -> left = malloc(sizeof(NODE));
	a -> right = malloc(sizeof(NODE));
	a -> left = NULL;
	a -> right = NULL;
	a -> val = i;
	t -> root = iaux(t -> root, a);
}

int naux(NODE* n) {
	return (n == NULL) ? 0 : 1 + naux(n -> left) + naux(n -> right);
}

int nnode(TREE* t) {
	return naux(t -> root);
}

int haux(NODE* n, int h) {

	if (n == NULL) return h;

	h++;
	int hl = haux(n -> left, h);
	int hr = haux(n -> right, h);

	return (hl > hr) ? hl : hr;

}

int height(TREE* t) {

	haux(t -> root, 0);

}

void eord(TREE* t) {

	NODE base = *(t -> root);
	NODE* nlist;

	nlist = malloc((height(t)+1) * sizeof(NODE));
	nlist[0] = base;

	int i = 0;
	while (i >= 0) {
		base = nlist[i--];
		printf("%d ", base.val);
		if (base.left != NULL) nlist[++i] = *(base.left);
		if (base.right != NULL) nlist[++i] = *(base.right);
	}
	printf("\n");
	free(nlist);

}

int main() {

	TREE tree;
	init(&tree);

	show(&tree);

	insert(&tree, 10);
	insert(&tree, 15);
	insert(&tree, 16);
	insert(&tree, 17);
	insert(&tree, 14);
	insert(&tree, 5);
	insert(&tree, 30);
	insert(&tree, 1);

	show(&tree);

	eord(&tree);

	return 0;

}
