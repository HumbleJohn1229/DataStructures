#include <stdio.h>
#include "ArrayStack.h"

void main() {
	Stack* stack = init_stack(5);
	push(stack, 5);
	push(stack, 4);
	push(stack, 3);
	push(stack, 2);

	printf("%d", pop(stack));
	printf("%d", pop(stack));
	printf("%d", pop(stack));
}