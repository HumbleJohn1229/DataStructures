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

// �Է� ���� ���ڿ��� ���������� �ƴ��� �Ǻ� �Լ�
int is_opr(char opr) {
	return opr == '+' || opr == '-' || opr == '*' || opr == '/';
}

// �Է¹��� �������� ���� ������� ��ȯ�ϴ� �Լ� 
int val_opr(char opr) {
	if (opr == '+' || opr == '-')
		return 1;
	else if (opr == '*' || opr == '/')
		return 2;

	return 0;
}

// �� �������� ������� �����ִ� �Լ�
int cmp_opr(char opr1, char opr2) {
	return val_opr(opr1) >= val_opr(opr2);
}

// CPU���� ó�� ���ִ� ��� ����� ��� ����� �������� ���� sub ����
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

// ���� �����ڿ��� ���� �����ڷ� ��ȯ�� �迭���� ���� ���� ��� �Լ�.
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

// ���� �����ڸ� ���� �����ڷ� �ٲپ� �ִ� �Լ�
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