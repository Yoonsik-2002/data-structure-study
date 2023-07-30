#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// include 할 헤더파일 명시
#include <stdio.h>
#include <stdlib.h>

// 상수 및 메크로 정의

// 사용자 type정의 : type, struct 등
typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
	struct tagNode* NextNode;
} Node;

// 전역변수 선언

// 함수 선언
Node* SSL_CreateNode(ElementType NewData);
void SSL_DestroyNode(Node* Node);
Node* SSL_AppendNode(Node** Head, Node* NewNode);
void SSL_InsertNodeAfter(Node* Current, Node* NewNode);
void SSL_InsertNewHead(Node** Head, Node* NewNode);
void SSL_RemoveNode(Node** Head, Node* Remove);
Node* SSL_GetNodeAt(Node* Head, int Location);
int SSL_GetNodeCount(Node* Head);

#endif