#include<stdio.h>


int main() {

	int c, i, nwhite, nother;
	int digit[10];
	nwhite = nother = 0;

	for (i = 0; i < 10; i++) digit[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++digit[c - '0'];
		} else if (c == '\t' || c == '\n' || c == ' ') {
			++nwhite;
		} else {
			++nother;
		}

	}

	for (i = 0; i < 10; i++) {
		printf("There are %d number of #%d\n",digit[i], i);
	}

	printf("And there are %d white space characters, and %d other characters", nwhite, nother);

	return 0;
}
