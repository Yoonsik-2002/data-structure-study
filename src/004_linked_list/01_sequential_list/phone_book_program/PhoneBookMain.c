#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList.h"

void main() {
	List list;
	NameCard * pcard;
	char tempArr[PHONE_LEN];
	
	ListInit(&list);
	
	// 기능 1) 총 3명의 전화번호 정보를 앞서 구현한 리스트에 저장
	pcard = MakeNameCard("조윤식", "010-2342-2342");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("김소정", "010-2342-2222");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("장준혁", "010-2343-3333");
	LInsert(&list, pcard);
	
	// 기능 1-1) 현재 전화번호부에 저장되어 있는 모든 정보를 출력
	if(LFirst(&list, &pcard))
	{
		printf("A LIST OF PHONE BOOKS\n");
		printf("---------------------\n");
		ShowNameCardInfo(pcard);
		
		while(LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}
	
	// 기능 2) 특정 이름을 대상으로 탐색을 진행하여 그 사람의 정보 출력(김소정)
	if(LFirst(&list, &pcard))
	{
		if(!NameCompare(pcard, "김소정"))
		{
			ShowNameCardInfo(pcard);
			printf("\n");
		}
		else 
		{
			while(LNext(&list, &pcard)) 
			{
				if(!NameCompare(pcard, "김소정")) 
				{
					ShowNameCardInfo(pcard);
					printf("\n");
					break;
				}
			}
		}
	}
	
	// 기능 3) 특정 이름을 대상으로 탐색을 진행하여 그 사람의 전화번호를 변경 (장준혁)
	if(LFirst(&list, &pcard))
	{
		if(!NameCompare(pcard, "김소정"))
		{
			printf("enter %s's new phone number : ", pcard -> name);
			scanf("%s", tempArr);
			
			ChangePhoneNumber(pcard, tempArr);
			
			printf("\n");
		}
		else
		{
			while(LNext(&list, &pcard)) 
			{
				if(!NameCompare(pcard, "김소정"))
				{
					printf("enter %s's new phone number : ", pcard -> name);
					scanf("%s", tempArr);
					
					ChangePhoneNumber(pcard, tempArr);
					
					printf("\n");
					break;
				}
			}
		}
	}
	
	// 기능 4) 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보 삭제(장준혁)
	if(LFirst(&list, &pcard)) 
	{
		if(!NameCompare(pcard, "장준혁")) 
		{
			pcard = LRemove(&list);
			printf("deled %s's information\n", pcard -> name);
			printf("\n");
			
			free(pcard);
		}
		else 
		{
			while(LNext(&list, &pcard)) 
			{
				if(!NameCompare(pcard, "장준혁"))
				{
					pcard = LRemove(&list);
					printf("deleted %s's information\n", pcard -> name);
					printf("\n");	
					free(pcard);
					
		
					break;
				}
			}
		}
	}
	
	// 기능 5) 삭제 후, 남아있는 데이터들을 출력해준다. 
	if(LFirst(&list, &pcard))
	{
		printf("[A LIST OF PHONE BOOKS]\n");
		printf("-----------------------\n");
		ShowNameCardInfo(pcard);
		
		while(LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}
}

