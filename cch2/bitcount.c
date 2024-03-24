#include<stdio.h>
#define INT_SIZE sizeof(int) * 8
int bitcount(int num);
int main() {
	printf("%d\n", bitcount(0b1111));
	printf("%d\n", bitcount(0b0101));
	printf("%d\n", bitcount(0b0000));
	return 0;
}


int bitcount(int num) {
	/*Counts the 1 bits in the given number*/
	int cntr, i;
	cntr = 0;
	for (i = 0; i < INT_SIZE; ++i) {
		cntr += (num >> i) & 1;
	}
	return cntr;
} 
