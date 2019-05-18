#include "Que.h"
#include <stdio.h>

int main()
{
	//Que queue;
	//init(&queue);
	int arr[5] = { 1,2,3,4,5 };
	int k = 1;
	int data;
	data = arr[(k++) % 5];
	printf("%d, %d", data, k);
	getchar();
	
}