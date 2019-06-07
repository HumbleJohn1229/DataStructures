#pragma once

typedef int node_data;
typedef struct _node {
	//struct _node* parent;
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
Node* copy_node(Node* node);
void traverse(Node*);
void traverse_use_for(Node*);
void destroy_tree(Tree*);

