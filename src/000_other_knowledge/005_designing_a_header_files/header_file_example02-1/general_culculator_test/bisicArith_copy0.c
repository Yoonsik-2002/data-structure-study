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