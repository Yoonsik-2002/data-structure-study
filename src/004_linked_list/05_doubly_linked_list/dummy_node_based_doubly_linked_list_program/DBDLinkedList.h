#ifndef __DBDLinkedList_H__
#define __DBDLinkedList_H__

#define TRUE 	1
#define FALSE	0

typedef int Data;

/* 양방향 연결 리스트의 노드를 나타내는 구조체 */
typedef struct _node {
	struct _node * next;
	struct _node * prev;
	Data data;
} Node;

/* 양방향 연결 리스트를 나타내는 구조체 */
typedef struct _DBDLinkedList {
	Node * head;
	Node * tail;
	Node * cur;
	
	int numOfData;
} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List * pList);
void LInsert(List * pLIst, Data data);

int LFirst(List * pList);
int LNext(List * pLIst, Data * pData);
int LPrev(List * pList, Data * pData);

Data LRemove(List * pList);
int LCount(List * pList);

#endif