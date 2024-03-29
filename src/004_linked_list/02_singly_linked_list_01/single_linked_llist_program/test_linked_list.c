#include "linked_list.h"

void main()
{
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;
	
	// 노드 5개 추가
	for(i = 0; i < 5; i++) {
		NewNode = SSL_CreateNode(i); 
		SSL_AppendNode(&List, NewNode);
	}
	
	// 링크트 리스트의 새로운 헤드 노드 추가
	NewNode = SSL_CreateNode(-1);
	SSL_InsertNewHead(&List, NewNode);
	
	// 링크드 리스트의 새로운 헤드 노드 추가
	NewNode = SSL_CreateNode(-2);
	SSL_InsertNewHead(&List, NewNode);
	
	// 리스트 출력
	Count = SSL_GetNodeCount(List);
	
	for (i = 1; i <= Count; i++) {
		Current = SSL_GetNodeAt(List, i);
		
		printf("List[%d] : %d \n", i, Current -> Data);
	}
	
	// 리스트의 세 번째 노드 뒤에 새로운 노드 삽입
	printf("\n Inserting 3000 After [3] ... \n\n");
	
	Current  = SSL_GetNodeAt(List, 3);
	NewNode = SSL_CreateNode(3000);
	
	SSL_InsertNodeAfter(Current, NewNode);
	
	// 리스트 출력
	Count = SSL_GetNodeCount(List);
	
	for (i = 1; i <= Count; i++) {
		Current = SSL_GetNodeAt(List, i);
		
		printf("List[%d] : %d \n", i, Current -> Data);
	}
	
	// 링크드 리스트 내의 모든 노드를 메모리에서 제거
	printf("\n Destroying List ...\n");
	
	for (i = 0; i < Count; i++) {
		Node* Current = SSL_GetNodeAt(List, 1);
		
		if(Current != NULL) {
			SSL_RemoveNode(&List, Current);
			SSL_DestroyNode(Current);
		}
	}
	
	// 모든 노드 소멸 확인 
	if(List == NULL) {
		printf("\n-----------------------------------------------\n");
		printf("\n\n All nodes in the linked list have been deleted. \n\n");
	}
}