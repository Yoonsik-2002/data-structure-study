#include <stdio.h>

typedef struct {
	char name[20];
	char phone_num[25];
	int age;
}person;

person read_person_info(void){
	person man;
	printf("--Input Information of person--\n");
	printf("Name : "); scanf("%s", man.name);
	printf("Phone Number : "); scanf("%s", man.phone_num);
	printf("Age : "); scanf("%d", &man.age);
	printf("-------------------------------\n");
	puts("");
	return man;
}

void show_person_info(person a){
	printf("----Information of %s----\n", a.name);
	printf("Name : %s\n", a.name);
	printf("Phone Number : %s\n", a.phone_num);
	printf("Age : %d\n", a.age);
	printf("-----------------------------\n");
}

int main()
{
	person man = read_person_info();
	show_person_info(man);
}