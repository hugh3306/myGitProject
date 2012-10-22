#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarytree.h"
#include "linklist.h"

int insert_value(BTreeNode **root, int value) {
	if (*root == NULL) {
		*root = (BTreeNode*)malloc(sizeof(BTreeNode));
		if (*root == NULL)
			printf("%s : malloc failed\n", __func__);
		(*root)->value = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return 0;
	}

	if (value < (*root)->value) {
		insert_value(&((*root)->left), value);
	} else {
		insert_value(&((*root)->right), value);
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

void breadth_first_traversal(BTreeNode *start) {
	ListElement *root = NULL;
	ListElement *queueNode = NULL;
	BTreeNode *current = start;

	if (start == NULL) {
		printf("%s : the tree is empty\n", __func__);
		return;
	}

	queueNode = (ListElement*) malloc(sizeof(ListElement));
	memset(queueNode, 0, sizeof(ListElement));
	queueNode->treeNode = current;
	enqueue(&root, queueNode);

	do {
		queueNode = dequeue(&root);
		current = queueNode->treeNode;
		free(queueNode);
		queueNode = NULL;
		printf("value : %d\n", current->value);

		if (current->left != NULL) {
			queueNode = (ListElement*) malloc(sizeof(ListElement));
			memset(queueNode, 0, sizeof(ListElement));
			queueNode->treeNode = current->left;
			enqueue(&root, queueNode);
		}
		if (current->right != NULL) {
			queueNode = (ListElement*) malloc(sizeof(ListElement));
			memset(queueNode, 0, sizeof(ListElement));
			queueNode->treeNode = current->right;
			enqueue(&root, queueNode);
		}


	} while (root != NULL);
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
		printf("3 : breadth_first_traversal\n");
		printf("0 : exit\n");
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
			case 3:
				printf("do bfs\n");
				breadth_first_traversal(root);
				printf("end do bfs\n");
				break;
			default:
				operation = -1;
				break;
		}
	}
	
	return 0;
}
