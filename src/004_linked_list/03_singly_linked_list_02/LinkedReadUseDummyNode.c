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
	
	Node * DummyNode = NULL; // 더미 노드 생성
	Node * newNode = NULL; // 새 노드 생성
	int readData; // 데이터 입력받음
	
	
	/* Dummy Node 추가*/
	DummyNode = (Node *)malloc(sizeof(Node));
    DummyNode -> data = 0;
	DummyNode -> next = NULL;
	
	head = DummyNode; // 연결 리스트의 맨 앞(head)에 빈 노드인 DummyNode를 미리 추가
	
	
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
		
		if(head -> next == NULL) { // DummyNode 다음 노드가 존재하지 않는 경우
			tail = DummyNode; // tail도 DummyNode를 가리킴
			
			tail -> next = newNode; // DummyNode의 다음 노드로 유효한 데이터를 지닌 노드를 연결(유효한 데이터를 지니 노드는 두번째 노드 부터 시작 됨)
		}
		
		else
			tail -> next = newNode; // 링크드 리스트에 다른 노드가 존재하는 경우 - 마지막 노드의 next에 newNode를 저장하여 연결
		
		tail = newNode; // 새로 추가한 노드가 결국, 현 시점에서는 제일 마지막 노드. tail에 저장
	}
	printf("\n");
	
	
	/* 입력받은 데이터의 출력 */
	printf("Full output of data received\n");
	
	if(head -> next == NULL) // DummyNode 다음 노드가 존재하지 않는 경우(유효한 데이터를 지닌 노드가 존재하지 않는 경우)
	{
		printf("Stored data does not exist\n");
	}
	else 
	{
		cur = head -> next; // cur이 두 번째 노드를 가리킴(DummyNode 바로 다음 노드를 가리킴)
		printf("%d ", cur -> data);
		
		while(cur -> next != NULL)
		{
			cur = cur -> next; // cur이 다음 노드를 가리키게 함
			printf("%d ", cur -> data);
		}
	}
	printf("\n\n");
	
	
	/* 메모리 해제 */
	if(head -> next == NULL)
	{
		return 0;
	}
	else
	{
		Node * delNode = head -> next;
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