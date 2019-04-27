#pragma once

/* Linked list
내부에 노드가 있고 노드를 통해 리스트를 구현한다.
각 노드는 data와 다음 노드를 가리키는 주소값을 가지고 있다.

리스트 안에는 맨 처음 노드의 주소값을 가지고 있는 head, for문을 위한 index, 전체 싸이즈를 가리키는 size가 있다.

- 구현 함수 리스트
1. push : head가 비어있는지를 체크해서 없다면 head에 넣어준다. head가 비어 있다면 새로운 노드를 만들고 맨 마지막 노드를 찾아서 맨 만지막 노드의 next 값에 넣어준다.
1-1. push index : 해당 인덱스를 찾는다. 입력된 인덱스가 현재 사이즈보다 크다면 -1을 반환한다. 입력된 인덱스 직전 인덱스의 노드를 찾는다. 새로운 노드를 만들고 데이터를 넣고 next 값에 찾은 노드의 next값을 넣어준다. 직전 노드의 next 값에 현재 노드의 주소값을 넣어준다.
2. pop : 비어 있는 경우 -1을 반환한다. 비어있지 않다면 맨 마지막 노드를 찾아서 데이터 저장 시키고 free 시켜주고, 맨 마지막 직전 노드의 next 값을 null로 바꿔준다. 마지막으로 저장해놓은 데이터를 반환한다.
2-1. pop : 비어 있거나 입력받은 인덱스가 size보다 크다면 -1을 반환한다. 그렇지 않다면 해당 직전, 해당, 해당 다음 노드의 주소값을 찾고, 해당 직전의 next 값을 해당 다 노드의 주소값으로 바꿔준다. 해당 노드의 데이터를 저장하고 free한다. 마지막으로 데이터를 반환한다.
3. 입력받은 데이터로 찾기 : 비어 있는 경우 -1을 반환한다. 비어있지 않다면 head부터 데이터 값을 비교한다. 마지막까지 검색하며 중간에 값이 나온 경우 해당 1을 반환한다. 값이 없는 경우는 0을 반환한다.
4. index로 찾기 : 비어 있거나 입력받은 index가 size보다 크다면 null 반환. 아니라면 해당 인덱스의 데이터를 반환.
5. index 초기화 : 인덱스에 head의 주소값을 넣는다.
6. 다음 노드 있는지 확인 : 현재 index가 가리키는 노드의 next 값을 체크해서 null값에 따라 1 또는 0을 반환한다.
7. 다음 값 반환 : index가 next를 가리키도록 하고 index가 가리키게 된 노드의 데이터를 반환한다.
*/
 

// 관련 변수 선언

typedef int node_data;

typedef struct _node {
	node_data data;
	struct _node* next;
} Node;

typedef struct linked_list {
	Node* head;
	Node* index;
	int size;
} List;


List* makeLinkedList();
int push(List*, node_data);
int push_index(List*, node_data, int);
node_data pop(List*);
node_data pop_index(List*, int);
int findIndexByData(List*, node_data);
node_data findDataByIndex(List*, int);
int initInternalIndex(List*);
int hasNext(List*);
node_data retNextVal(List* list);
Node* returnLast(List*);

int is_empty(List*);
int clean_list(List*);