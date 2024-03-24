#include<stdio.h>
#define IN 1;
#define OUT 0;
int main() {

	int c;
	int state = OUT;
	while ((c = getchar()) != EOF) {
		if(c == '\n' || c == '\b' || c == '\t' || c == ' ' && !state) {
			state = OUT;
		}
		else if (c == '\n' || c == '\b' || c == '\t' || c == ' ' && state) {
			state = OUT;
			putchar('\n');
		}
		else {
			state = IN;
			putchar(c);
		}
	}
	return 0;

}
