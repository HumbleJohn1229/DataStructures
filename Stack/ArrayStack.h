#pragma once


/*
	Stack ADT
- init_stack : 스택의 크기를 입력 받아 빈 스택을 하나 만들어 반환한다.
- is_empty : 해당 스택이 비어 있는지 확인한다. 비어있으면 1, 비어 있지 않으면 0을 반환한다.
- is_full : 해당 스택이 다 차 있는지 여부를 확인한다. 다 차있다면 1, 다 차있지 않다면 0을 반환한다. 
- push : 스택에 데이터를 넣는다. 성공하면 1, 실패하면 0을 반환한다.
- pop : 스택의 데이터를 빼온다. 빼온 데이터는 스택에서 사라진다. 빼올 데이터가 없을 경우 NULL을 반환한다.
- peek : 맨 마지막에 넣은 데이터를 확인만 한다. 해당 데이터는 스택에서 사라지지 않는다. 빼올 데이터가 없는 경우 NULL을 반환한다.
- destroy_stack : 스택을 안전하게 없애준다. 안에 선언되어 있는 배열의 메모리를 해제해준다.
*/

//변수 선언
typedef int s_data;

//flexible array member 로 인해 arr은 매 마지막으로 가야 함.
typedef struct _stack {
	int size;
	int inx;
	s_data arr[];
} Stack;

//함수 선언
Stack* init_stack(int);
int is_empty(Stack*);
int is_full(Stack*);
int push(Stack*, s_data);
s_data pop(Stack*);
s_data peek(Stack*);
int destroy_stack(Stack*);

