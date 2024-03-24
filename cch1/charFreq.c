#include<stdio.h>

int main() {
	int i, c,j;
	int chars[256];

	for (i = 0; i < 256; ++i) {
		chars[i] = 0;
	}


	while ((c = getchar()) != EOF) {
		++chars[c];
	}

	for (i = 0; i < 256; ++i) {
		for (j = 0; j < chars[i]; ++j) {
			printf("|");
		}
		printf("\n");
	}

	return 0;
}
