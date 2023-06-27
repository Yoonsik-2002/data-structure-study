#include <stdio.h>
#include <stdbool.h>

// #define ADD 
#define MIN // 매크로의 값(매크로 몸체)을 정의해 주지 않아도 됨

void main()
{
  int num1, num2;
  printf("두 개의 정수를 입력 : ");
  scanf("%d %d", &num1, &num2);

  #ifndef ADD
    printf("%d + %d = %d", num1, num2, num1 + num2);
  #endif

  #ifndef MIN
    printf("%d - %d = %d", num1, num2, num1 - num2);
  #endif
}