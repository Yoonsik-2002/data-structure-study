#include <stdio.h>
#include <stdbool.h>

// #define ADD true
#define MIN false

void main()
{
  int num1, num2;
  printf("두 개의 정수를 입력 : ");
  scanf("%d %d", &num1, &num2);

  #ifdef ADD
    printf("%d + %d = %d", num1, num2, num1 + num2);
  #endif

  #ifdef MIN
    printf("%d - %d = %d", num1, num2, num1 - num2);
  #endif
}