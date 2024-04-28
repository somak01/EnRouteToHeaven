#include<stdio.h>
#include<string.h>

int is_digit(int c);
/*extended version of atof, with scientific notation*/
double atof_extended(char[]);
double power(double, int);
int main() {
	char test1[] = "123.45e-2";
	char test2[] = "123.45";
	char test3[] = "-123.444E-6";
	printf("%.10f\n", atof_extended(test1));
	printf("%.10f\n", atof_extended(test2));
	printf("%.10f\n", atof_extended(test3));



	return 0;
}

int is_digit(int c) {
	if (c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

double power(double num, int pow) {
	double result = 1;
	if (pow >= 0) {
		for (int i = 0; i < pow; i++ ) {
			result *= num;	
		} }
	else {
		for (int i = 0; i < -pow; i++) {
			result /= num;
		}
	}
	return result;
}


double atof_extended(char num[]) {
	double res = 0;
	int i, c, digits_after_decimal_point;
	int sign = 1;
	int exponent = 0;
	int exp_flag = 0;
	int exp_sign = 1;
	int decimal_flag = 0;
	digits_after_decimal_point = 0;
	i = 0;
	c = num[i];
	if (c == '-' || c == '+') {
		sign = c == '-' ? -1 : 1;
		i++;
	}
	for (i = i; i < strlen(num); i++) {
		c = num[i];
		if (c == '.') {
			decimal_flag = 1;
		} else if (c == 'e' || c == 'E') {
			exp_flag = 1;	
		} else if (exp_flag && c == '-' || c == '+') {
			exp_sign = (c == '-') ? -1 : 1;
		} else if (exp_flag) {
			exponent *=10;
			exponent += c - '0'; 
		} else {
			if (decimal_flag) digits_after_decimal_point++;
			res *= 10;
			res += c - '0';
		}
	}
	res /= power(10, digits_after_decimal_point);
	res *= power(10, exp_sign * exponent);
	return sign * res;
}
