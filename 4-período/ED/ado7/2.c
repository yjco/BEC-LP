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

int aaux(NODE* n) {
	if (n == NULL || n->left == NULL || n->right == NULL) return 1;
	if (n->left->val > n->right->val) {
		return 0;
	} else {
		return aaux(n -> left) && aaux(n -> right);
	}
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

	printf("%s\n", abbt(&tree) ? "TRUE" : "FALSE");

	return 0;

}
