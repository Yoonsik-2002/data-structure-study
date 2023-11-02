#ifndef __NameCard_h__
#define __NameCard_h__

#define NAME_LEN	30
#define PHONE_LEN	30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN]
} NameCard;


//NameCard 구조체 변수의 동적 할당 및 초기화 후 주소값 반환
