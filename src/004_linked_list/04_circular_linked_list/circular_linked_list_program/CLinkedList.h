#ifndef __C_LINKEDLIST_H__
#define __C_LINKEDLIST_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node {
	Date data;
	struct _node * next;
} Node;

typedef struct _CLL {
	struct _CLL * tail;  // 원형 연결 리스트의 마지막 노드(꼬리)를 참조하는 구조체 포인터 변수
	struct _CLL * cur;  // 현재 참조하고 있는 원형 연결 리스트의 노드를 나타내는 구조체 포인터 변수
	struct _CLL * before;  // cur바로 이전 노드를 참조하는 구조체 포인터 변수
	
	int numOfdata;
} CList;

typedef CList List;

void ListInit(List * pList);
void LInsert(List * pList, Data data);
void LInsertFront(List * pList, Data data);

int LFirst(List * pList, Data * pData);
int LNext(List * pList, Data * pData);
Data LRemove(List * pList);
int LCount(List * pList);

#endif