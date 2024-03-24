#include<stdio.h>

/*Naive implementation of the atoi method
it converts string of digits to integer
it only accounts for situations where the
string contains only digits*/


int somatoi(char s[]);


int main() {
	char number[] = "123421\0";
	int int_num = somatoi(number);
	printf("%d", int_num);
	return 0;
}

int somatoi(char s[]) {
	int num, i;
	num = 0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9') {
		num = num * 10 + (s[i] - '0');
		++i;
	}
	return num;

}
