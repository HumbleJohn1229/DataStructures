#include <stdio.h>
#include "Tree.h"
#include "Stack.h"

void main() {
	
	Tree* tree = make_init_tree();
	insert(tree, 5);
	insert(tree, 3);
	insert(tree, 4);
	insert(tree, 7);
	//insert(tree, 9);
	
	//del(tree, 7); del 처리 추가해주어야 함.

	// preorder
	printf("\n##pre\n");
	traverse_pre(tree->root);
	traverse_for_pre(tree->root);

	// inorder
	printf("\n##in\n");
	traverse_in(tree->root);
	traverse_for_in(tree->root);

	// postorder
	printf("\n##post\n");
	traverse_post(tree->root);
	traverse_for_post(tree->root);

	destroy_tree(tree);
}