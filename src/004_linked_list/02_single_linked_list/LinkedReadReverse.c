/* question 04-1

기존 연결리스트의 경우, 연결리스트의 head부터 순서대로 새 노드를 tail에 추가하였었다. 
이번 문제에서는 반대로, 연결리스트의 head에 노드가 추가되도록 구현할 것을 요구한다. 


              head
기존 연결리스트 : 1 -> 2 -> 3 -> 4 -> 5
                                  tail

                          tail 
문제에서 요구되는 연결 리스트 : 5 -> 4 -> 3 -> 2 -> 1
                                               head(start)
*/


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	typedef struct _node {
		int data;
		struct _node * next;
	} Node;
	
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;
	
	Node * newNode = NULL;
	
	int readData;
	
	/* 데이터 입력 */
	while(1) {
		printf("Iniput data : ");
		scanf("%d", &readData);
		
		if(readData < 1)
			break;
		
		newNode = (Node *)malloc(sizeof(Node));
		newNode -> data = readData;
		newNode -> next = NULL;
		
		if(head == NULL) {  // 링크드 리스트가 비어 있는 경우 - head가 NULL인 경우, 처음 생성된 새 노드를 가리키게 함
			head = newNode;
		}
		
		else {
			newNode -> next = tail; // 두번째로 링크드 리스트에 추가되는 노드는, tail이 가리키는 노드를 가리키게 함
		}
		
		tail = newNode; // tail 새로 추가된 노드는 tail이 가리킴
	}
	printf("\n");
	
	
	/* 입력된 데이터 출력 */
	printf("Full output of data received\n");
	
	if(head == NULL) {
		printf("Stored data does not exist.");
	}
	
	else {
		cur = tail;
		printf("%d ", cur -> data);
		
		while(cur -> next != NULL) {
			cur = cur -> next;
			printf("%d ", cur -> data);
		}
	}
	printf("\n\n");
	
	
	/* 노드 삭제 및 메모리 해제 */
	if(tail == NULL) {
		return 0;
	}
	
	else {
		Node * delNode = tail;
		Node * delNodeNext = delNode -> next;

		printf("delete %d\n", delNode -> data);
		free(delNode);
	
		while(delNodeNext != NULL){
			delNode = delNodeNext;
			delNodeNext = delNode -> next;
			
			printf("delete %d\n", delNode -> data);
			free(delNode);
		}
	}
	
}