#include<stdio.h>


int main() {
	int c, counter;
	counter = 0;

	while ((c = getchar()) != EOF) {
		if (c != '\n') ++counter;
	}

	printf("There were %d characters entered!\n", counter);
	return 0;
}
