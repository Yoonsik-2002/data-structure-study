#include "linked_list.h"

// 노드 생성
Node* SSL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode -> Data = NewData;
	NewNode -> NextNode = Null;
	
	return NewNode;
}

// 노드 소멸
void SSL_DestroyNode(Node* Node) {
	free(Node);
}

// 노드 추가
void SSL_AppendNode(Node** Head, Node* NewNode) {
	// 헤드 포인터가 아무것도 가리키고 있지 않은 경우, 즉 링크드 리스트가 비어있는 경우
	if((*Head) == Null) {
		*Head = NewNode;
	}
	
	// 링크드 리스트가 비어있지 않은 경우
	else {
		Node* Tail = (*Head); // 헤드 포인터에서 부터 시작하여, 마지막 노드를 탐색
		
		while(Tail -> NextNode != Null) {
			Tail = Tail -> NextNode;
		}
		
		Tail -> NextNode = NewNode;
		
		
	}
}