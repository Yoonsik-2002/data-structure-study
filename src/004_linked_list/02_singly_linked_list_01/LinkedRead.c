#include <stdio.h>
#include <stdlib.h>

typedef struct _Node { // 구조체 형태로 구현된 노드 - int형 데이터를 저장하는 data, 다음 노드를 가리키는 구조체 포인터 변수 next로 구성 
	int data;
	struct _Node * next; 
} Node;

int main(void) {
	Node * head = NULL; // 연결 리스트의 첫 번째 노드를 가리키는 구조체 포인터 변수 head
	Node * tail = NULL; // 연결 리스트의 마지막 노드를 가리키는 구조체 포인터 변수 tail
	Node * cur = NULL; // 저장된 데이터의 조회에 사용되는 포인터 변수(해당 포인터 변수가 가리키는 노드를 조회)
	
	Node * newNode = NULL; // 새 노드 생성(비어있음)
	int readData; // 데이터 입력받음
	
	
	/* 데이터의 입력 */
	while(1) 
	{
		printf("Input Data : ");
		scanf("%d", &readData);
		if(readData < 1) // 0을 입력받으면 종료
			break;
		
		newNode = (Node *)malloc(sizeof(Node)); // 새 노드 생성
		newNode -> data = readData;
		newNode -> next = NULL;
		
		if(head == NULL)
			head = newNode; // 링크드 리스트가 비어있는 경우 - 첫 번째 노드를 가리키는 head에 newNode저장
		
		else
			tail -> next = newNode; // 링크드 리스트에 다른 노드가 존재하는 경우 - 마지막 노드의 next에 newNode를 저장하여 연결
		
		tail = newNode; // 새로 추가한 노드가 결국, 현 시점에서는 제일 마지막 노드. tail에 저장
	}
	printf("\n");
	
	
	/* 입력받은 데이터의 출력 */
	printf("Full output of data received\n");
	
	if(head == NULL) 
	{
		printf("Stored data does not exist\n");
	}
	else 
	{
		cur = head;
		printf("%d ", cur -> data);
		
		while(cur -> next != NULL)
		{
			cur = cur -> next; // cur이 다음 노드를 가리키게 함
			printf("%d ", cur -> data);
		}
	}
	printf("\n\n");
	
	
	/* 메모리 해제 */
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		Node * delNode = head;
		Node * delNodeNext = delNode -> next;
		
		printf("delete %d.\n", delNode -> data);
		free(delNode);
		
		while(delNodeNext != NULL)
		{
			delNode = delNodeNext;
			delNodeNext = delNode -> next;
			
			printf("delete %d.\n", delNode -> data);
			free(delNode);
		}
	}
	
	return 0;
}