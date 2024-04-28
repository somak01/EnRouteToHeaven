#include<stdio.h>
#include<string.h>


/*converts the given string(properly, given it contains only digits, a decimal point and a sign), to a floating point(double) number*/
double atof(char[]);
double power(double, int);
int main() {
	
	char num[] = "-123";
	double res = atof(num);
	printf("%f", res);
	return 0;
}

double power(double number, int power) {
	double result = 1;	
	for (int i = 0; i < power; i++) {
		result *= number;	
	}
	return result;
}
double atof(char num[]) {
	double result = 0;
	int i, c;
	int digits_after_decimal_point = 0;
	int flag = 0;
	int negative_flag = 0;
	for (i = 0; i < strlen(num); i++) {
		if (flag) {
		digits_after_decimal_point++;
		}	
		c = num[i];
		if (c == '-' || c == '+') negative_flag = (c == '-') ? -1 : 1;
		else if (c == '.') flag = 1;
		else {
			result *= 10;
			result += (c - '0');
		}
	}
	return result / power(10, digits_after_decimal_point) * negative_flag;
}
