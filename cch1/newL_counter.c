#include<stdio.h>


int main() {
	int c,cntr;
	cntr = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')	++cntr;
	}	

	printf("\nThere were %d new lines typed!\n", cntr);

	return 0;
}
