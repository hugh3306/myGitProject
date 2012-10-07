#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

int insert_in_front(ListElement **head, int data) {
	ListElement *newElement = (ListElement*)malloc(sizeof(ListElement));
	if(NULL == newElement) {
		printf("%s : malloc fail", __func__);
		return -1;
	}

	newElement->data = data;
	newElement->next = *head;
	*head = newElement;

	return 0;
}

int main() {
	printf("Hello World!!\n");
	return 0;
}
