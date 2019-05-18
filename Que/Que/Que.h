#pragma once

// Que : FIFO(First In First Out) �ڷ���
// init : �̸� ������ ũ���� ť�� ����� �ش�.
// push : ť�� �����͸� �ִ´�. �̹� ���� �ִ� ��� 0�� ��ȯ�Ѵ�.
// peek : ť���� �����͸� Ȯ���Ѵ�. Ȯ���� �����ʹ� �������� �ʴ´�. �����Ͱ� ���� ��� NULL�� ��ȯ�Ѵ�.
// pop : ť���� �����͸� �����´�. ������ �����ʹ� ť���� �������. �����Ͱ� ���� ��� NULL�� ��ȯ�Ѵ�.
// isFull : ť�� ������ �ִٸ� 1, ���� ���� �ʾҴٸ� 0�� ��ȯ�Ѵ�.
// isEmpty : ť�� ��� �ִٸ� 1, ������� �ʴٸ� 0�� ��ȯ�Ѵ�.
// destroy : ť�� �޸𸮿��� �����Ѵ�.

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
