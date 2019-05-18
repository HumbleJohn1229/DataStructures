#include <stdio.h>
#include "Que.h"

void init(Que* newQue) {
	newQue->arr_size = MAX_SIZE_ARRAY;
	newQue->front = 0;
	newQue->rear = 0;
};
int push(Que* que, q_data data) {
	if (isFull(que))
		return 0;

	que->rear = que->rear+1 % que->arr_size;
	(que->arr)[que->rear] = data;
	return 1;
};
q_data peek(Que* que) {
	if (isEmpty(que))
		return NULL;
	return (que->arr)[que->front];
};

q_data pop(Que* que) {
	if (isEmpty(que)) 
		return NULL;
	
	q_data retVal = (que->arr)[que->front++];
	que->front = que->front % que->arr_size;
	return retVal;
};

int isFull(Que* que) {
	return (que->rear + 1) % (sizeof(que->arr) / sizeof(que->arr[0]) - 1) == que->front; 
};

int isEmpty(Que* que) {
	return que->front == que->rear;
};
void destroy(Que* que) {
	que->front = 0;
	que->rear = 0;
};