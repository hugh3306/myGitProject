#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

#define ENTER() printf("%s+\n")

int insert_in_front(ListElement **head, int data) {
	ListElement *newElement = (ListElement*)malloc(sizeof(ListElement));
	if(NULL == newElement) {
		printf("%s : malloc fail\n", __func__);
		return -1;
	}

	newElement->data = data;
	newElement->next = *head;
	*head = newElement;

	return 0;
}

ListElement* find(ListElement *head, int data) {

	while(NULL != head && head->data != data) {
		head = head->next;
	}

	return head;
}

void traverse_list(ListElement *head) {
	int index = 0;
	while (head != NULL) {
		printf("list %d : %d\n", index, head->data);
		index++;
		head = head->next;
	}
}

int delete_element(ListElement **head, ListElement *delete) {
	ListElement *element = *head;

	if (delete == *head) {
		*head = element->next;
		free(delete);
		return 0;
	}

	while (element) {
		 if (element->next == delete) {
		 	element ->next = delete->next;
			free(delete);
			return 0;
		 }
		 element = element->next;
	}
	printf("%s do not fine elemnt to delete\n");
}

void delete_list(ListElement **head) {
	ListElement *element = *head;

	while (element) {
		ListElement *next = element->next;
		free(element);
		element = next;
	}

	*head = NULL;
}

int main() {
	int opcode = -1;
	int data;
	ListElement *head;

	while (opcode != 0) {
		printf("select operation :\n");
		printf("1 : insert a data to list\n");
		printf("2 : find a data in list\n");
		printf("3 : traverse list\n");
		printf("4 : delete element\n");
		printf("0 : end operation\n");
		scanf("%d", &opcode);
		switch (opcode) {
			case 1:
				printf("input a data to insert: ");
				scanf("%d", &data);
				printf("insert data %d into list\n", data);
				insert_in_front(&head, data);
				break;
			case 2:
				printf("input a data to find: ");
				scanf("%d", &data);
				ListElement *node = find(head, data);
				if (node != NULL) {
					printf("find data in list!!!!\n");
				}
				break;
			case 3:
				traverse_list(head);
				break;
			case 4:
				printf("input a data to delete: ");
				scanf("%d", &data);
				node = find(head, data);
				delete_element(&head, node);
			default:
				break;
		}
	}

	return 0;
}
