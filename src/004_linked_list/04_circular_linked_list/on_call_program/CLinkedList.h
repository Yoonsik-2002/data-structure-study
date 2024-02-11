#ifndef __C_LINKEDLIST_H__
#define __C_LINKEDLIST_H__

#define TRUE	1
#define FALSE	0

#include "Employee.h"

typedef Employee* Data;

typedef struct _node {
	Data data;
	struct _node * next;
} Node;

typedef struct _CLL {
	Node * tail;
	Node * cur;
	Node * before;
	
	int numOfData;
}CList;

typedef CList List;

void ListInit(List * pList);
void LInsert(List * pList, Data data);
void LInsertFront(List * pList, Data data);

int LFirst(List * pList, Data * pData);
int LNext(List * pLIst, Data * pData);
Data LRemove(List * pList);
int LCount(List * pList);

#endif