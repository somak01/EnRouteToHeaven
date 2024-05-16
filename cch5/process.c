#include<stdio.h>
#define BUFFER_SIZE 100
int BUFFER[BUFFER_SIZE];
int b_pointer = 0;
int getch() {
	return b_pointer > 0 ? BUFFER[--b_pointer] : getchar();	
}

void ungetch(int c) {
	if (b_pointer < BUFFER_SIZE) {
		BUFFER[b_pointer++] = c;
		printf("\nWhat the hell\n");
	} else {
		printf("error: buffer overflow\n");
	}
}
