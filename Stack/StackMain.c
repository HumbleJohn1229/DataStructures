#include <stdio.h>
#include "ArrayStack.h"

#if 0
// stack operation check
void main() {
	Stack* stack = init_stack(5);
	push(stack, 5);
	push(stack, 4);
	push(stack, 4);

	int* tmp = stack->arr;
	tmp = tmp + 3;

	printf("%d", pop(stack));
	printf("%d", pop(stack));
	printf("%d", pop(stack));

	destroy_stack(stack);
	free(tmp);
	printf("ok");
	//printf("%d", pop(stack));
}

/*
const char const* make_array(char* p)
{
	p = (char*)malloc(sizeof(char) * 5);
	return p;

	const char* k = 100;
	k = 200;
	char* p = &k;
}
*/
#endif

// 입력 받은 문자열이 연산자인지 아닌지 판별 함수
int is_opr(char opr) {
	return opr == '+' || opr == '-' || opr == '*' || opr == '/';
}

// 입력받은 연산자의 연산 운선순위를 반환하는 함수 
int val_opr(char opr) {
	if (opr == '+' || opr == '-')
		return 1;
	else if (opr == '*' || opr == '/')
		return 2;

	return 0;
}

// 두 연산자의 운선순위를 비교해주는 함수
int cmp_opr(char opr1, char opr2) {
	return val_opr(opr1) >= val_opr(opr2);
}

// CPU에서 처리 해주는 계산 기능을 대신 사용할 목적으로 만든 sub 계산기
int subCal(char opr, int a, int b) {
	if (opr == '+') return a + b;
	else if (opr == '-') return a - b;
	else if (opr == '*') return a * b;
	else if (opr == '/') {
		if (b == 0) {
			return 0;
		}
		return a / b;
	}
}

// 중위 연산자에서 후위 연산자로 변환된 배열에서 최종 값을 얻는 함수.
int cal_fi_val(char arr[]) {
	Stack* stack = init_stack(10);

	int inx = 0;
	while (arr[inx] != NULL) {
		char tmp = arr[inx++];
		if (is_opr(tmp)) {

			int a = pop(stack) - '0';
			int b = pop(stack) - '0';

			push(stack, subCal(tmp,b ,a ) + '0');

		}
		else {
			push(stack, tmp);
		}
	}
	int ret_tmp = pop(stack) - '0';
	//destroy_stack(stack);
	return ret_tmp;
}

// 중위 연산자를 후위 연산자로 바꾸어 주는 함수
char* cvt_infix_to_postfix(char arr[], char ret_arr[], int stack_size) {

	Stack* st_opr = init_stack(stack_size);
	int inx = 0;
	int ret_inx = 0;

	while (arr[inx] != NULL) {

		char tmp = arr[inx++];

		if (!is_opr(tmp)) {
			ret_arr[ret_inx++] = tmp;
			continue;
		}

		if (is_empty(st_opr)) {
			push(st_opr, tmp);
		} else {
			while (cmp_opr(peek(st_opr), tmp)) {
				ret_arr[ret_inx++] = pop(st_opr);
			}
			push(st_opr, tmp);
		}
	}

	while (!is_empty(st_opr)) {
		ret_arr[ret_inx++] = pop(st_opr);
	}
	ret_arr[ret_inx] = NULL;
	destroy_stack(&st_opr);
		
	return ret_arr;
}



void main() {
	char* arr = "3+2*5/2";
	//char arr[10] = {'5','+','4','*','3','+','2', NULL};
	char ret_arr[10];
	cvt_infix_to_postfix(arr, ret_arr, 10);
	int fiVal = cal_fi_val(ret_arr);
	printf("postfix : %s\n", ret_arr);
	printf("result : %d", fiVal);
}