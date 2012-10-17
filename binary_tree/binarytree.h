#ifndef BINARYTREE_H
#define BINARYTREE_H


typedef struct BTreeNode {
	int value;
	struct BTreeNode *left;
	struct BTreeNode *right;
} BTreeNode;

#endif
