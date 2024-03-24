#include<stdio.h>
#define MAXSIZE 1000


int lower(int c) {
	if (c >= 'A' && c <= 'Z'){
		return (c + ('a' - 'A'));
	}
	else return c;
}

int main() {
	char c = 'A';
	char c2 = 'K';
	char c3 = 'Y';
	char c5 = '!';
	printf("%c\n", lower(c));
	printf("%c\n", lower(c2));
	printf("%c\n", lower(c3));
	printf("%c\n", lower(c5));

	
	return 0;
}
