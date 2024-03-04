#ifndef __DB_LINKEDLIST_H__
#define __DB_LINKEDLIST_H__

#define TRUE 	1
#define	FALSE 	0

typedef int Data;

/* 양방향 연결 리스트의 노드를 표현하는 구조체 */
typedef struct _node {
	struct _node * next;
	struct _node * prev;
	Data data;
} Node;

/* 양방향 연결 리스트를 표현하는 구조체 */
typedef struct _dbLinkedList {
	Node * head;
	Node * cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

/* 프로그램에 사용되는 함수들의 선언 */
void ListInit(List * pList);
void LInsert(List * pList, Data data);
int LFirst(List * pList, Data * pData);
int LNext(List * pList, Data * pData);
int LPrev(List * pList, Data * pData);

#endif