#include<stdio.h>
#include<limits.h>
#define MAXSIZE 1024



void itoa(int, char*);
void reverse(char s[]);
int size(char s[]);
int abs(int num);
void itoa_other_idea(int num, char str[]);

int main() {
	char str[MAXSIZE];
	int num = -5;
	itoa(num, str);
	printf("%s\n", str);
	int num2 = 0;
	itoa(num2, str);
	printf("%s\n", str);
	int num3 = 3231313;
	itoa(num3, str);
	printf("%s\n", str);
	itoa(INT_MIN, str);
	printf("%s", str);
	itoa_other_idea(INT_MIN, str);
	printf("%s", str);

	return 0;
	
}
int abs(int num) {
	return (num > 0) ? num : -num;
}

void itoa_other_idea(int num, char str[]) {
	int i, sign;
	unsigned n;
	i = 0;
	if ((sign = num) < 0) {
		n = -num;
	} else {
		n = num;
	}
	do {
		str[i++] = n % 10 + '0';
	} while ((n/=10));
	if (sign) str[i++] = '-';
	str[i] = '\0';
	reverse(str);
}
void itoa(int num, char str[]) {
	int i,  sign;
	sign = num;
	i = 0;
	do{
		str[i++] =  abs(num % 10) + '0';
	} while ((num/=10));

	if (sign < 0) {
		str[i++] = '-';
	}
	str[i] = '\0';
	reverse(str);
}

int size(char s[]) {
	int i = 0;
	while (s[i] != '\0') {
		i++;	
	}
	return i;
}
void reverse(char s[]) {
	int i, j;
	for (i = 0, j = size(s)-1; i < j; i++, j--) {
		int tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
	
