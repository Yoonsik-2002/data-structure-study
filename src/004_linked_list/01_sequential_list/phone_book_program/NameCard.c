#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<NameCard.h>

// MakeNameCard - Namecard 구조체 변수의 동적할당 및 초기화 후, 주소값 반환
NameCard * MakeNameCard(char * name, char * point) {
	NameCard * newCard = (NameCard *)malloc(sizeof(NameCard));
	
	strcpy(newCard -> name, name);  // name에 저장되어 있는 문자열 전체를 newCard -> name에 복사 하는 방식으로 초기화.
	strcpy(newCard -> phone, phone);
	
	return newCard;
}

// ShowNameCardInfo - NameCard 구조체 변수의 정보(멤버값) 출력
void ShowNameCardInfo(NameCard * pcard) {
	printf("name : %s\n phone number : %s\n", pcard -> name, pcard -> phone);
}