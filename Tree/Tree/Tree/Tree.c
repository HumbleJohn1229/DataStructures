#include <stdio.h>
#include "Tree.h"
#include "Stack.h"



Tree* make_init_tree() {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}

// # recursive -> for 출력만 recursive
int insert(Tree* tree, node_data data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	Node** temp = &(tree->root);

	while (*temp)
	{
		if ((*temp)->data > data)
			temp = &((*temp)->left);
		else if ((*temp)->data < data)
			temp = &((*temp)->right);
		else
			return 0;
	}

	*temp = new_node;
	return 1;
};

/* 입력 받은 값을 지운다. 찾아서 지운 경우 1, 찾지 못한 경우에는 0을 반환한다.*/
int del(Tree* tree, node_data data) {
	Node** temp = &(tree->root);

	while (*temp) {
		if ((*temp)->data > data)
			temp = &((*temp)->left);
		else if ((*temp)->data < data)
			temp = &((*temp)->right);
		else
		{
			*temp = NULL;
			return 1;
		}
	}
	return 0;
};

node_data find(Tree* tree, node_data data) {
	Node** temp = &(tree->root);

	while (*temp) {
		if ((*temp)->data > data)
			temp = &((*temp)->left);
		else if ((*temp)->data < data)
			temp = &((*temp)->right);
		else
			return (*temp)->data;
	}
	return NULL;
};

void traverse_pre(Node* node) {
	if (!node)
		return;
	printf("%d\n", node->data);
	traverse_pre(node->left);
	traverse_pre(node->right);
}

void traverse_in(Node* node) {
	if (!node)
		return;
	traverse_in(node->left);
	printf("%d\n", node->data);
	traverse_in(node->right);
}


void traverse_post(Node* node) {
	if (!node)
		return;
	traverse_post(node->left);
	traverse_post(node->right);
	printf("%d\n", node->data);
}


void traverse_for_pre(Node* node) {
	printf("for\n");
	Stack* stack = init_stack();
	push(stack, node);

	while (!is_empty(stack)) {
		Node* tmp = pop(stack);
		printf("%d\n", tmp->data);

		if (tmp->right != NULL) {
			push(stack, tmp->right);
		}

		if (tmp->left != NULL) {
			push(stack, tmp->left);
		}
	}
	destroy_stack(stack);
}

void traverse_for_in(Node* node) {
	printf("for\n");
	Stack* stack = init_stack();
	push(stack, node);
	Node* pop_tmp = NULL;
	while (!is_empty(stack)) {
		Node* tmp = peek(stack);

		if (tmp->left == pop_tmp
			|| (tmp->left == NULL && tmp->right == NULL)) {
			pop_tmp = pop(stack);
			printf("%d\n", pop_tmp->data);
			continue;
		} else if (tmp->left == NULL) {
			pop_tmp = pop(stack);
			printf("%d\n", tmp->data);
			push(stack, tmp->right);
			continue;
		}

		if (tmp->right != NULL) {
			pop(stack);
			push(stack, tmp->right);
			push(stack, tmp);
		}
		push(stack, tmp->left);
	}
	destroy_stack(stack);
}

void traverse_for_post(Node* node) {
	printf("for\n");
	Stack* stack = init_stack();
	push(stack, node);
	Node* pop_tmp = NULL;
	while (!is_empty(stack)) {
		Node* tmp = peek(stack);

		if ((tmp->right == NULL && tmp->left == NULL)
			|| (tmp->right == pop_tmp)
			|| (tmp->left == pop_tmp && tmp->right == NULL)) {
			pop_tmp = pop(stack);
			printf("%d\n", pop_tmp->data);
			continue;
		}

		if (tmp->right != NULL) {
			push(stack, tmp->right);
		}

		if (tmp->left != NULL) {
			push(stack, tmp->left);
		}
	}
	destroy_stack(stack);
}

void trv_destroy(Node* node) {
	if (!node)
		return;
	trv_destroy(node->left);
	trv_destroy(node->right);
	free(node);
}

void destroy_tree(Tree* tree) {
	trv_destroy(tree->root);
};