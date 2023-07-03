#include "stdiv.h"
#include <stdio.h>

extern Div int_div(int num1, int num2);

void main()
{
  Div val = int_div(6, 8);

  printf("몫 : %d\n", val.quotient);
  printf("나머지 : %d\n", val.remainder);
}