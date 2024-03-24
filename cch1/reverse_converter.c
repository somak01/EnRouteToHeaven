#include<stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP_SIZE 20


int main() {
	printf("\n");
	for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP_SIZE) {
		printf("%d\t%3.2f\n", fahr, (fahr-32)*(5.0/9));
	}
	return 0;
}
