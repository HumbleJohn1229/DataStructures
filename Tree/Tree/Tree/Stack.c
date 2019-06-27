#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/* This function is not used because of error during free. It will be used after soving this problem.
Stack* init_stack(int size) {
	Stack* new_stack = (Stack*)malloc(sizeof(Stack)+size*sizeof(s_data));
	new_stack->size = size;
	new_stack->inx = -1;
	return new_stack;
}
*/

Stack* init_stack() {
	Stack* new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->size = MAX_SIZE_ARRAY;
	new_stack->inx = -1;
	return new_stack;
}

int is_empty(Stack* stack) {
	return stack->inx == -1;
}

int is_full(Stack * stack) {
	return stack->inx + 1 >= stack->size;
}
int push(Stack * stack, s_data data) {
	if (is_full(stack))
		return 0;
	(stack->arr)[++(stack->inx)] = data;
	return 1;
}
s_data pop(Stack * stack) {
	if (is_empty(stack))
		return NULL;
	s_data _retData = (stack->arr)[(stack->inx)];
	(stack->arr)[(stack->inx)--] = NULL;
	return _retData;
}

s_data peek(Stack * stack) {
	if (is_empty(stack))
		return 0;
	return	(stack->arr)[(stack->inx)];
}

int destroy_stack(Stack **stack) {
	if (stack == NULL)
		return;
	free(*stack);
	*stack = NULL;
}

// java try, catch 처럼 에러가 나는 경우 다른 값을 리턴해줄 수는 없을까?
/*
int destroy_stack(Stack* stack) {
	//free(stack->arr);
	free(stack);
	printf("stack free sucess!\n");
	return 1;
}
*/