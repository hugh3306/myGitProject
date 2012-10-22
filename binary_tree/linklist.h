#ifndef LINKLISH_H
#define LINKLISH_H

typedef struct ListElement {
	struct ListElement *next;
	int data;
	void *treeNode;
} ListElement;

int enqueue(ListElement **head, ListElement *node);
ListElement *dequeue(ListElement **head);

#endif
