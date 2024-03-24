#include<stdio.h>
#define MAXSIZE 1000
#define LIMIT 100

int get_line(char*, int);


int main() {
	int c;
	int i = 0;
	while ((c = getchar()) != EOF) {
		++i;
		putchar(c);
	}

	return 0;
}
