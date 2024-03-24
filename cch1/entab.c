#include<stdio.h>
#define TABSIZE 8

int main() {
    int c, x, spaces;
    x  = spaces = 0;

    while ((c = getchar()) != EOF) {
	if (c == ' ') {
		++spaces;
	}else if (spaces == 0) 
	{
		putchar(c);
		x++;
	} else if (spaces == 1) {
		putchar(' ');
		putchar(c);
		x=+2;
		spaces = 0;
	} else {
		while (x / TABSIZE != (x+spaces) / TABSIZE) {
			putchar('\t');
			++x;
			--spaces;
			while (x % TABSIZE > 0) {
				++x;
				--spaces;
			}
		}
		while (spaces > 0) {
			putchar(' ');
			++x;
			--spaces;
		}
		putchar(c);
		++x;
	}
	if (c == '\n') {
		x = 0;
	}
	
}
    return 0;
    }
