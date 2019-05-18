#pragma once

// Que : FIFO(First In First Out) 자료형
// init : 미리 정해진 크기의 큐를 만들어 준다.
// push : 큐에 데이터를 넣는다. 이미 꽉차 있는 경우 0을 반환한다.
// peek : 큐에서 데이터를 확인한다. 확인한 데이터는 지워지지 않는다. 데이터가 없는 경우 NULL을 반환한다.
// pop : 큐에서 데이터를 가져온다. 가져온 데이터는 큐에서 사라진다. 데이터가 없는 경우 NULL을 반환한다.
// isFull : 큐가 가득차 있다면 1, 가득 차지 않았다면 0을 반환한다.
// isEmpty : 큐가 비어 있다면 1, 비어있지 않다면 0을 반환한다.
// destroy : 큐를 메모리에서 제거한다.

#define MAX_SIZE_ARRAY  10

typedef int q_data;

typedef struct _que {
	q_data arr[MAX_SIZE_ARRAY];
	int arr_size;
	int front;
	int rear;
} Que;

void init(Que*);
int push(Que*, q_data);
q_data peek(Que*);
q_data pop(Que*);
int isFull(Que*);
int isEmpty(Que*);
void destroy(Que*);
