#include<stdio.h>



int main() {
	//if (getchar() != EOF == 0) printf("it seems like a 0\n");
	//if (getchar() != EOF == 1) printf("it seems like a 1\n");
	printf("%d", EOF);
	int c;
	while ((c = getchar()) != -1) {
		putchar(c);
	}
	return 0;
}
