#pragma once
#include"Tree.h"

/*
	Stack ADT
- init_stack : ������ ũ�⸦ �Է� �޾� �� ������ �ϳ� ����� ��ȯ�Ѵ�.
- is_empty : �ش� ������ ��� �ִ��� Ȯ���Ѵ�. ��������� 1, ��� ���� ������ 0�� ��ȯ�Ѵ�.
- is_full : �ش� ������ �� �� �ִ��� ���θ� Ȯ���Ѵ�. �� ���ִٸ� 1, �� ������ �ʴٸ� 0�� ��ȯ�Ѵ�.
- push : ���ÿ� �����͸� �ִ´�. �����ϸ� 1, �����ϸ� 0�� ��ȯ�Ѵ�.
- pop : ������ �����͸� ���´�. ���� �����ʹ� ���ÿ��� �������. ���� �����Ͱ� ���� ��� NULL�� ��ȯ�Ѵ�.
- peek : �� �������� ���� �����͸� Ȯ�θ� �Ѵ�. �ش� �����ʹ� ���ÿ��� ������� �ʴ´�. ���� �����Ͱ� ���� ��� NULL�� ��ȯ�Ѵ�.
- destroy_stack : ������ �����ϰ� �����ش�. �ȿ� ����Ǿ� �ִ� �迭�� �޸𸮸� �������ش�.
*/

#define MAX_SIZE_ARRAY 200

typedef Node* s_data;

/* This function is not used because of error during free. It will be used after soving this problem.
//flexible array member �� ���� arr�� �� ���������� ���� ��.
typedef struct _stack {
	int size;
	int inx;
	s_data arr[];
} Stack;
Stack* init_stack(int);
*/

typedef struct _stack {
	s_data arr[MAX_SIZE_ARRAY];
	int size;
	int inx;
} Stack;

//�Լ� ����
Stack* init_stack();
int is_empty(Stack*);
int is_full(Stack*);
int push(Stack*, s_data);
s_data pop(Stack*);
s_data peek(Stack*);
int destroy_stack(Stack*);

