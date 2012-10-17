#include <stdio.h>
#include <stdlib.h>

#include "binarytree.h"

int insert_value(BTreeNode **root, int value) {
	BTreeNode *node = *root;
	if (node == NULL) {
		node = (BTreeNode*)malloc(sizeof(BTreeNode));
		if (node == NULL)
			printf("%s : malloc failed\n", __func__);
		node->value = value;
		node->left == NULL;
		node->right == NULL;
		return 0;
	}

	if (value < node->value) {
		insert_value(&(node->left), value);
	} else {
		insert_value(&(node->right), value);
	}

	return 0;
}

void preorder_traversal(BTreeNode *root) {
	if (root == NULL) {
		return;
	}

	printf("value = %d\n", root->value);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

int main(int argc, const char *argv[])
{
	BTreeNode *root = NULL;	
	int operation = 0;
	int value = 0;


	while (operation != -1) {
		printf("operations\n");
		printf("1 : insert a value\n");
		printf("2 : show the tree\n");
		scanf("%d", &operation);
		switch (operation) {
			case 1:
				printf("input a value to insert:");
				scanf("%d", &value);
				insert_value(&root, value);
				break;
			case 2: {
				printf("do preorder_traversal\n");
				preorder_traversal(root);
				printf("end preorder_traversal\n");
				break;
				}
			default:
				operation = -1;
				break;
		}
	}
	
	return 0;
}
