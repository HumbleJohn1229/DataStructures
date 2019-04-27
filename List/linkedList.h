#pragma once

/* Linked list
���ο� ��尡 �ְ� ��带 ���� ����Ʈ�� �����Ѵ�.
�� ���� data�� ���� ��带 ����Ű�� �ּҰ��� ������ �ִ�.

����Ʈ �ȿ��� �� ó�� ����� �ּҰ��� ������ �ִ� head, for���� ���� index, ��ü ����� ����Ű�� size�� �ִ�.

- ���� �Լ� ����Ʈ
1. push : head�� ����ִ����� üũ�ؼ� ���ٸ� head�� �־��ش�. head�� ��� �ִٸ� ���ο� ��带 ����� �� ������ ��带 ã�Ƽ� �� ������ ����� next ���� �־��ش�.
1-1. push index : �ش� �ε����� ã�´�. �Էµ� �ε����� ���� ������� ũ�ٸ� -1�� ��ȯ�Ѵ�. �Էµ� �ε��� ���� �ε����� ��带 ã�´�. ���ο� ��带 ����� �����͸� �ְ� next ���� ã�� ����� next���� �־��ش�. ���� ����� next ���� ���� ����� �ּҰ��� �־��ش�.
2. pop : ��� �ִ� ��� -1�� ��ȯ�Ѵ�. ������� �ʴٸ� �� ������ ��带 ã�Ƽ� ������ ���� ��Ű�� free �����ְ�, �� ������ ���� ����� next ���� null�� �ٲ��ش�. ���������� �����س��� �����͸� ��ȯ�Ѵ�.
2-1. pop : ��� �ְų� �Է¹��� �ε����� size���� ũ�ٸ� -1�� ��ȯ�Ѵ�. �׷��� �ʴٸ� �ش� ����, �ش�, �ش� ���� ����� �ּҰ��� ã��, �ش� ������ next ���� �ش� �� ����� �ּҰ����� �ٲ��ش�. �ش� ����� �����͸� �����ϰ� free�Ѵ�. ���������� �����͸� ��ȯ�Ѵ�.
3. �Է¹��� �����ͷ� ã�� : ��� �ִ� ��� -1�� ��ȯ�Ѵ�. ������� �ʴٸ� head���� ������ ���� ���Ѵ�. ���������� �˻��ϸ� �߰��� ���� ���� ��� �ش� 1�� ��ȯ�Ѵ�. ���� ���� ���� 0�� ��ȯ�Ѵ�.
4. index�� ã�� : ��� �ְų� �Է¹��� index�� size���� ũ�ٸ� null ��ȯ. �ƴ϶�� �ش� �ε����� �����͸� ��ȯ.
5. index �ʱ�ȭ : �ε����� head�� �ּҰ��� �ִ´�.
6. ���� ��� �ִ��� Ȯ�� : ���� index�� ����Ű�� ����� next ���� üũ�ؼ� null���� ���� 1 �Ǵ� 0�� ��ȯ�Ѵ�.
7. ���� �� ��ȯ : index�� next�� ����Ű���� �ϰ� index�� ����Ű�� �� ����� �����͸� ��ȯ�Ѵ�.
*/
 

// ���� ���� ����

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