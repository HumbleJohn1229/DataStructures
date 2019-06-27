#pragma once
//#include "C:\\workspace\\DataStructures\\Tree\\Tree\\Tree\\ArrayStack.h"

typedef int node_data;
typedef struct _node {
	node_data data;
	struct _node* left;
	struct _node* right;
} Node;


typedef struct _tree {
	Node* root;
} Tree;

Tree* make_init_tree();
int insert(Tree*, node_data);
int del(Tree*, node_data);
node_data find(Tree*, node_data);
int isEmpty(Tree*);
void traverse_pre(Node*);
void traverse_in(Node*);
void traverse_post(Node*);
void traverse_for_pre(Node*);
void traverse_for_in(Node*);
void traverse_for_post(Node*);
void destroy_tree(Tree*);

