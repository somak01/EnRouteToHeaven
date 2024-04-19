#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1024
/*Once again*/
void reverse(char s[]);
void itoa_fixed_min_space(int n, char s[], int l);
int abs(int n);


int main() {

	char s[MAX_SIZE];
	itoa_fixed_min_space(1024, s, 16);
	printf("%s", s);
	return 0;
}

int abs(int n) {
	return (n > 0) ? n : -n;
}
void reverse(char s[]) {
	int i, j, c;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa_fixed_min_space(int n, char s[], int l) {
	int i, sign;
	sign = n;	
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while (n /= 10); 
	if (sign < 0) s[i++] = '-';
	while (i < l) s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}
