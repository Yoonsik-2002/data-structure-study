typedef struct def {
	int quotient;	// 몫
	int remainder;  // 나머지
} Div;

Div int_div (int num1, int num2) {
	Div div;
	div.quotient = num1 / num2;
	div.remainder = num1 % num2;
	
	return div;
}