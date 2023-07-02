# 1 "basicArith_copy0.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "basicArith_copy0.c"
double Add (double num1, double num2) {
 return num1 + num2;
}

double Min (double num1, double num2) {
 if(num1 > num2)
  return num1 - num2;
 else
  return num2 - num1;
}

double Mul (double num1, double num2) {
 return num1 * num2;
}

double Div (double num1, double num2) {
 return num1 / num2;
}
