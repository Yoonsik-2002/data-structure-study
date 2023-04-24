#include <stdio.h>

typedef struct tagNode{
	int Data;
	struct tagNode* NextNode;
}Node;

Node* SSL_CreateNode(int NewData)
{
	Node NewNode; // 자동메모리에 새로운 노드 생성
	
	NewNode.Data = NewData;
	NewNode.NextNode = Null;
	
	return &NewNode;
}

void main()
{
	Node* MyNode = SSL_CreateNode(911);
}

