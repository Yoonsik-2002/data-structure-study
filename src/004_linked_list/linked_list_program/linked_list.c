#include "linked_list.h"

// 노드 생성
Node* SSL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode -> Data = NewData;
	NewNode -> NextNode = Null;
	
	return NewNode;
}

// Head 영역에서의 노드 삭제
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

// 노드 삽입
// 일반적으로, 양 노드 사이에 새 노드를 삽입하는 경우
void SSL_InsertNodeAfter(Node* Current, Node* NewNode) {
	NewNode -> NextNode = Current -> NextNode;
	Current -> NextNode = NewNode;
}

// 링크드 리스트의 새 헤드(새 첫번째 노드)를 삽입하는 경우
void SSL_InsertNewHead(Node** Head, Node* NewNode) {
	if(*Head == Null) {
		(*Head) = NewNode;
	}
	
	else {
		NewNode -> NextNode = (*Head);
		(*Head) = NewNode;
	}
}

// 링크드 리스트 에서의 노드 삭제
void SSL_RemoveNode(Node** Head, Node* Remove) {
	if(*Head == Remove) {
		(*Head) = Remove -> NextNode;
	}
	
	else {
		Node* Current = (*Head);
		
		while(Current != Null && Current -> NextNode != Remove) {
			Current = Current -> NextNode;
		}
		
		if(Current != Null) {
			Current -> NextNode = Remove -> NextNode;
		}
	}
}


// 노드 탐색
Node* SSL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head; // 첫 번재 노드에서 부터 탐색을 시작
	
	/* 첫 번째 노드는 이미 구조체 포인터 변수 Current가 가리키고 있기 때문에
	구지 탐색하지 않고 바로 Current를 리턴해주면 됨 */
	
	while(Current != Null && (--Location) > 0) { 
		Current = Current -> NextNode;
	}
	
	return Current;
}

// 노드 수 세기
int SSL_GetNodeCount(Node* Head) {
	int Count = 0;
	
	Node* Current = Head;
	
	while(Current != Null) {
		Current = Current -> NextNode;
		Count++;
	}
	
	return Count;
}