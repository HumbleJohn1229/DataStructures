#include "linkedList.h"
#include <stdio.h>

int main()
{
	// add List
	List* list = makeLinkedList();
	push_index(list, 1, 1);
	push_index(list, 2, 2);
	push_index(list, 1, 0);
	push_index(list, 2, 1);
	printf("%d", findIndexByData(list, 2));

	return 0;
}