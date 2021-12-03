#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* NODE com H *

typedef struct node {
	int val;
	int height;
	struct node* left;
	struct node* right;
} NODE;

NODE* init(int val) {
	NODE* n = malloc(sizeof(NODE));
	n -> val = val;
	n -> left = NULL;
	n -> right = NULL;
	n -> height = 0;
	return n;
}

int height(NODE* n) { return (!n) ? -1 : n -> height; }
int bigger(int i, int j) { return (i > j) ? i : j; }

NODE* rright(NODE* n) {

	NODE* m;
	m = n -> left;

	n -> left = m -> right;
	m -> right = n;

	n -> height = bigger(height(n -> left), height(n -> right)) + 1;
	m -> height = bigger(height(m -> left), n -> height) + 1;

	return m;

}

NODE* rleft(NODE* n) {

	NODE* m;
	m = n -> right;

	n -> right = m -> left;
	m -> left = n;

	n -> height = bigger(height(n -> right), height(n -> left)) + 1;
	m -> height = bigger(height(m -> right), n -> height) + 1;

	return m;

}

NODE* insert(NODE* root, int val) {

	if (!root) return init(val);

	if (val < root -> val) {
		root -> left = insert(root -> left, val);
		if (height(root -> left) - height(root -> right) == 2) {
			if (val < root -> left -> val) root = rright(root);
			else {
				root -> left = rleft(root -> left);
				root = rright(root);
			}
		}
	} else {
		if (val > root -> val) {
			root -> right = insert(root -> right, val);
			if (height(root -> right) - height(root -> left) == 2) {
				if (val > root -> right -> val) root = rleft(root);
				else {
					root -> right = rright(root -> right);
					root = rleft(root);
				}
			}
		}
	}
	root -> height = bigger(height(root -> right), height(root -> left));
	return root;
}

/* NODE com H */

/* NODE com FB */

typedef struct node {
	int val;
	int height;
	int factor;
	struct node* left;
	struct node* right;
} NODE;

NODE* init(int val) {
	NODE* n = malloc(sizeof(NODE));
	n -> val = val;
	n -> left = NULL;
	n -> right = NULL;
	n -> height = 0;
	n -> factor = 0;
	return n;
}

int height(NODE* n) { return (!n) ? -1 : n -> height; }
int factor(NODE* n) { return (!n) ? -1 : n -> factor; }
int bigger(int i, int j) { return (i > j) ? i : j; }

NODE* rright(NODE* n) {

	NODE* m;
	m = n -> left;

	n -> left = m -> right;
	m -> right = n;

	n -> height = bigger(height(n -> left), height(n -> right)) + 1;
	m -> height = bigger(height(m -> left), n -> height) + 1;

	n -> factor = n->left->height - n->right->height;
	m -> factor = m->left->height - m->right->height;

	return m;

}

NODE* rleft(NODE* n) {

	NODE* m;
	m = n -> right;

	n -> right = m -> left;
	m -> left = n;

	n -> height = bigger(height(n -> right), height(n -> left)) + 1;
	m -> height = bigger(height(m -> right), n -> height) + 1;

	n -> factor = n->left->height - n->right->height;
	m -> factor = m->left->height - m->right->height;

	return m;

}

NODE* insert(NODE* root, int val) {

	if (!root) return init(val);

	if (val < root -> val) {
		root -> left = insert(root -> left, val);
		if (root -> factor == 2) {
			if (val < root -> left -> val) root = rright(root);
			else {
				root -> left = rleft(root -> left);
				root = rright(root);
			}
		}
	} else {
		if (val > root -> val) {
			root -> right = insert(root -> right, val);
			if (root -> factor == -2) {
				if (val > root -> right -> val) root = rleft(root);
				else {
					root -> right = rright(root -> right);
					root = rleft(root);
				}
			}
		}
	}

	root -> height = bigger(height(root -> right), height(root -> left));
	root -> factor = (root->left == NULL) ? 0 : root->left->height - \
			 (root->right == NULL) ? 0 : root->right->height;
	return root;

}

/* NODE com FB */

void show(NODE* n) {
	printf("(");
	if (n != NULL) {
		printf("%d", n -> val);
		show(n -> left);
		show(n -> right);
	}
	printf(")");
}

void sort(int list[], int s, int* store) {

	NODE* tree = init(list[0]);
	for (int i = 1; i < s; i++) insert(tree, list[i]);

	int sorted[s];
	NODE* copy = tree;
	NODE* aux = malloc(5 * sizeof(NODE));

	NODE* temp;
	int i = 0, j = 0;
	int flag = 1;
	while (flag) {
		if (copy != NULL) {
			aux[i++] = *copy;
			copy = copy -> left;
		} else {
			if (j != s) {
				copy = &aux[--i];
				sorted[j++] = copy -> val;
				copy = copy -> right;
				temp = &aux[i];
				temp = NULL;
			} else flag = 0;
		}
	}

	free(aux);
	free(copy);
	free(tree);
	free(temp);

	memcpy(store, sorted, s*4);

}

int main() {

	int list[5] = { 5, 2, 3, 4, 1 };
	int* sorted = malloc(sizeof(int) * 5);
	sort(list, 5, sorted);
	for (int i = 0; i < 5; i++) printf("%d ", sorted[i]);
	printf("\n");

}
