#include <stdio.h>
#include "Tree.h"
#include "ArrayStack.h"


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

void traverse(Node* node) {
	if (!node)
		return;
	traverse(node->left);
	traverse(node->right);
	printf("%d\n", node->data);
}

Node* copy_node(Node* node){
    Node* c_node = (Node*)malloc(sizeof(Node));
    c_node->data=node->data;
    c_node->right=node->right;
    c_node->left=node->left;
}

void traverse_use_for(Node* node) {
	Stack* stack = init_stack();
    push(stack, copy_node(node));
  
	while (!is_empty(stack)){ 
        Node* tmp = peek(stack);
        
        if(tmp->right == NULL && tmp->left == NULL){
            printf("%d", pop(stack)->data);
            free(tmp);
            continue;
        } 
        
        if(tmp->right != NULL){  
            push(stack, copy_node(tmp->right));
            tmp->right = NULL;    
        }
	    
        if(tmp->left != NULL){
            push(stack, copy_node(tmp->left));
            tmp->left = NULL;
        }
	}
}

void traverse_use_for2(Node* node) {
    Stack* stack = init_stack();
    push(stack, copy_node(node));
  
    while (!is_empty(stack)){ 
        Node* tmp = pop(stack);
        printf("%d", tmp->data);
        
        if(tmp->right != NULL){  
            push(stack, copy_node(tmp->right));  
        }
        
        if(tmp->left != NULL){
            push(stack, copy_node(tmp->left));
        }
        free(tmp);
    }
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