#include <stdio.h>

#define HIT_NUM 7

void main()
{
  #if HIT_NUM==5
	printf("매크로 상수 HIT_NUM은 5입니다.");
  #elif HIT_NUM==6
  	printf("매크로 상수 HIT_NUM은 6입니다.");
  #elif HIT_NUM==7
  	printf("매크로 상수 HIT_NUM은 7입니다.");
  #else
  	printf("매크로 상수 HIT_NUM은 5, 6, 7이 아닙니다.");
  #endif
}