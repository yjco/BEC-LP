#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int he;
	int hd;
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
		printf("%d[%d][%d]", n -> val, n -> he, n -> hd);
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
		n -> he++;
		n -> left = iaux(n -> left, m);
	} else {
		n -> hd++;
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
	a -> he = 0;
	a -> hd = 0;
	t -> root = iaux(t -> root, a);
}

int aaux(NODE* n) {
	if (n -> left == NULL && n -> right == NULL) return 0;
	int fbe = (n -> left == NULL) ? 0 : aaux(n -> left);
	int fbd = (n -> right == NULL) ? 0 : aaux(n -> right);
	return (fbe > 1 || fbe < -1 || fbd > 1 || fbd < -1) ? 2 : n -> he - n -> hd;
}

int abbt(TREE* t) {
	return aaux(t -> root);
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

	show(&tree);

	int ret = abbt(&tree);
	printf("%s\n", (ret <= 1 || ret >= -1) ? "TRUE" : "FALSE");

	return 0;

}
