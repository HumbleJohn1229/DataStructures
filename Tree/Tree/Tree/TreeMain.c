#include <stdio.h>
#include "Tree.h"

int main() {
	Tree* tree = make_init_tree();
	insert(tree, 5);
	insert(tree, 4);
	insert(tree, 3);
	insert(tree, 7);

	printf("%d\n",find(tree, 7));
	del(tree, 7);
	traverse(tree->root);
	destroy_tree(tree);
}