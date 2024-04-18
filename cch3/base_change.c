#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1024

/*converts the given number to another base
* within the range of 2<=b<=37*/
void itob(int i, char s[], short b); 
/*just the regular reverse that I keep rewriting everytime*/
void reverse(char s[]);
int size(char s[]);


int main() {
	char char_num_repr[MAX_SIZE];
	for (int i = 2; i < 36; i++) {
		itob(1024, char_num_repr,i);
		printf("%s\n", char_num_repr);
	}
	return 0;
}

int size(char s[]) {
	int c,i;
	i = 0;
	while ((c = s[i++]) != '\0') 
		;
	return i-1;
}
void reverse(char s[]) {
	int i, j, c;
	for (i = 0, j = size(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}	
	
}


void itob(int n, char s[], short b) {
	char CHAR_RANGE[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, sign;
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = CHAR_RANGE[n % b];
	} while ((n /= b) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
