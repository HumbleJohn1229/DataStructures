#include "linkedList.h"
#include <stdio.h>

List* makeLinkedList() {
	List* retVal = (List*)malloc(sizeof(List));
	retVal->head = NULL;
	retVal->index = NULL;
	retVal->size = 0;
	return retVal;
}

int push(List* list, node_data data) {
	Node* nNode = (Node*)malloc(sizeof(Node));
	nNode->data = data;
	nNode->next = NULL;
	//!(list->head)
	//is_empty(&list)
	if (list->head == NULL) {
		list -> head = nNode;
	}
	else {
		returnLast(list)->next = nNode;
	}
	(list->size)++;
	return;
};

int push_index(List* list, node_data data, int index) {
	if (list->size < index) return 0;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (index == 0) {
		node->next = list->head;
		list->head = node;
		(list->size)++;
		return 1;
	}
	
	Node* curNode = list->head;
	
	
	for (int i = 1; i < index; i++) {
		curNode = curNode->next;
	}

	node->next = curNode->next;
	curNode->next = node;
	(list->size)++;
	return 1;
};

//이전 노드 next에 NULL값 넣기
node_data pop(List* list) {
	Node* node = list->head;
	Node* node_before = NULL;

	while (1) {
		if (node->next == NULL) {
			node_before->next = NULL;
			node_data data = node->data;
			free(node);
			(list->size)--;
			return data;
		};
		node_before = node;
		node = node->next;
	}
};

//int pop(List* list, int* pdata)
node_data pop_index(List* list, int index) {
	node_data data = NULL;
	if (list->size < index+1) return data;
	
	Node* node = list -> head;
	Node* node_before = NULL;

	for (int i = 0; i < index; i++) {
		node_before = node;
		node = node->next;
	}

	if (node_before != NULL) {
		node_before->next = node->next;
	}
	else 
	{
		list->head = (list->head)->next;
	}

	data = node->data;
	free(node);
	(list->size)--;
	return data;
};

int findIndexByData(List* list, node_data data) {
	if (list->size == 0) return 0;
	Node* node = list->head;
	int index = 0;
	while (1) {
		if (node->data == data) {
			return index;
		}
		node = node->next;
		index++;
	}
	return 0;
};
node_data findByIndex(List* list, int index) {
	if (list->size < ++index) return NULL;
	Node* node = list->head;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	return node -> data;
};
int initInternalIndex(List* list) {
	if (list->size == 0) return 0;
	list->index = list->head;
	return 1;
};
int hasNext(List* list) {
	Node* node = list->index;
	if (node->next == NULL) return 0;
	return 1;
};

node_data retNextNode(List* list) {
	if (!hasNext(list)) return NULL;

	Node* node = list->index;
	node = node->next;
	return node->data;	
};

Node* returnLast(List* list) {
	if (list->head == NULL)return NULL;
	Node* node = list -> head;
	while (1) {
		if (node->next == NULL) return node;
		node = node->next;
	}
};

