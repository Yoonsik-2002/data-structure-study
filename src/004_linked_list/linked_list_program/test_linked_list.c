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
}