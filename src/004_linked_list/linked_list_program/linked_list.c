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

// 노드 탐색
Node* SSL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;
	Location -= 1; // n번재 노드를 탐색하고 싶으면 Location에 n을 전달할 수 있도록 하기 위해 추가한 코드.(원래는 n번째 노드 탐색 시, n-1을 입력해야 했음)
	
	while(Current != Null && (--Locaton) >= 0) { // 애초에 Head가 첫 번째 노드를 가리키고 있기 때문에, 첫 번째 노드는 탐색할 필요 X
		Current = Current -> NextNode;
	}
	
	return Current;
}