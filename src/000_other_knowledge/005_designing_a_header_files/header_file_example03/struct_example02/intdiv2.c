#include "stdiv.h"

Div int_div(int num1, int num2) {
  Div div;

  div.quotient = num1 / num2;
  div.remainder = num1 % num2;
}