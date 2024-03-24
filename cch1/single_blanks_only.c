#include<stdio.h>



int main() {
	int c;
	int flag = 0;
	while ((c = getchar()) != EOF) {
		if (c !=' ' && flag) {
			putchar(' ');
			putchar(c);
			flag = 0;
		}
		else if (c!=' ') {
			putchar(c);
		} else {
			flag = 1;
		}
	}	

	return 0;

}
