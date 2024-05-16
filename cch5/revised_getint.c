#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "util.h"
#define NUMBER 1
#define NAN 0
#define ARR_SIZE 10

int getint(int* x);
void printarr(int arr[], int size);
int main() {
	int x, arr[ARR_SIZE];
	int arr_idx = 0;
	printf("Provide %d numbers somewhere in your input\n", ARR_SIZE);
	while (arr_idx < ARR_SIZE) {
		int flag = getint(&x);
		if (flag == NUMBER) arr[arr_idx++] = x;
		else {printf("Sad to see you go :(\n"); break;}
	}
	printarr(arr, arr_idx);
	
	

	return 0;
}

/*
*The return value supposed to indicate what happened
*did we get a number which is 1
*or did we get something else which is 0
*or it's end of file it returns -1
*and the actual int value if there's any is stored in the provided
*x value
*/
int getint(int* x) {
	*x = 0;
	int flag = 0;
	int c, sign;
	sign = 1;
	while ((isspace((c = getch())) || !isdigit(c)) && c != EOF) {
		if (c == '-' || c == '+') {
			int hold_sign = c;
			if (isdigit(c = getch())) {
				sign = hold_sign == '-' ? -1 : 1;
				break;
			}
		}	
	}
		
	while (isdigit(c) && c != EOF) {
		*x =*x * ARR_SIZE + (c - '0');
		flag = 1;
		c = getch();
	}
	if (flag) {
		*x *= sign;
		return NUMBER;
	} else {
		return c;
	}
}
void printarr(int arr[], int size) {
	printf("\nThe array %s: ", (size == ARR_SIZE) ? "" : "(it's not complete)");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
