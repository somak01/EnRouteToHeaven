#include<stdio.h>
#include<ctype.h>
#define BUFFER_SIZE 1024

int getch();
void ungetch(int c);
void swap(int *px, int *py);
int getint(int *pn);
void arrprint(int*, int);
int main() {
	int c, x, arr[10];
	while ((c = getint(&x)) != EOF) {
	printf("%s\n", x);
}
	return 0;
}
void arrprint(int *arr, int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {

		printf("%d ", arr[i]);
}
	printf("\n");
}
void swap(int *px, int *py) {
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int BUFFER[BUFFER_SIZE];
int BUFFER_POINTER = 0;
int getch() {
	return (BUFFER_POINTER > 0) ? BUFFER[--BUFFER_POINTER] : getchar();
}

void ungetch(int c) {
	if (BUFFER_POINTER < BUFFER_SIZE) {
		BUFFER[BUFFER_POINTER++] = c;
	}
	else {
		printf("Error: The buffer is full\n");
	}
}
	
int getint(int *pn) {
	int c, sign;
	while (isspace(c = getch())) 
		;
	if (!isdigit(c) && c != '+' && c != '-' && c != EOF){
	   	 ungetch(c);
		 return 0;
}
	sign = (c == '-') ? -1 : 1;
	c = getch();
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = *pn * 10 + c - '0';
	}
	*pn *= sign;
	if (c != EOF) ungetch(c);
	return c;
}
