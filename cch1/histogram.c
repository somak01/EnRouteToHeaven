#include<stdio.h>


#define IN 1
#define OUT 0


int main() {
	int c, state, i,j, length;
	int lengths[10];
	length = i = 0;
	state = OUT;	
	while (i < 10 && (c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			if  (state) {	
				lengths[i] = length;
				state = OUT;
				length = 0;
				++i;
			}
		} else {
			 ++length;
			 state=IN;
		}
	}

	for (j = 0; j < i;j++) {
		for (int k = 0; k < lengths[j]; k++) {
			printf("|");
		}
		printf("\n");
	}
	return 0;
}

