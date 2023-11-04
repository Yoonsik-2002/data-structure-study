#include <stdio.h>
#include <stdlib.h>
#include <sstring.h>
#include "NameCard.h"
#include "ArrayList.h"

main void() {
	List list;
	NameCard * pcard;
	NameCard compCard;
	
	ListInit(&list); // 리스트의 생성, numOfData, curPosition멤버들을 초기값으로 초기화
	
	// 1) 총 3명의 전화번호 정보를 앞서 구현한 리스트에 저장
	pcard = MakeNameCard("김소정", "010-2234-2232");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("김재민", "010-3729-2343");
	LInsert(&list, pcard);
	
	pcard = Makenamecard("조윤식", "010-3234-2432");
	LInsert(&list, pcard);
	
	// 2) 특정 이름(김소정)을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
	
}