#include<stdio.h>
enum boolean {NO, YES}; /*the first name in enum has the value of 0, the next 1, and so on unless explicit values are specified*/
enum months {JAN=1, FEB, MAR=5, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
/*if not all values are specified then the values continue from the last specified one*/


int str_len(const char[]);//here const indicates that the function will not change the value of the array
void is_leap(int year);
int main() {
	const double e = 2.71828182845905; // const says that the variable's value will not change
	const char msg[] = "warning: "; //const in arrays says that the elements of the array will not change
	printf("%d\n", FEB);
	is_leap(2000);
	is_leap(2001);
	is_leap(2002);
	is_leap(2003);
	is_leap(2004);
	is_leap(0);
	return 0;
}


int str_len(const char s[]) {
	int i = 0;
	while (i != '\0') {
		++i;
	}
	return i;
}


void is_leap(int year) {
/*a year is a leap year(february has 29 days) if 
it is divisible by 4 but not by 100 or is divisible by 400*/
	if (year % 4 == 0 && year %  100 != 0 || year % 400 == 0) {
		printf("The year %d is a leap year\n", year);
	}
	else {
		printf("the year %d is not a leap year\n", year);
	}
}
