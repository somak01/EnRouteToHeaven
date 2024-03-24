#include<stdio.h>
#define SET_ON 0b1101

int main() {
	int n;
	printf("%b\n", n);
	printf("%b\n", 0177);
	printf("%d\n", 0b11^0b01);
	printf("%d\n", 0b10|0b01);
	printf("Shifting left %d\n", 3<<1);
	printf("Shifting right %d\n", 1>>1);
	n = n & 0177;	
	
//	x = 1<<16;
	
	printf("%d\n", sizeof(int));
	printf("%d\n", 1<<sizeof(int)*8 - 1 );
	printf("%d\n", ~(1<<(sizeof(int)*8 - 1)));
	return 0;
}
