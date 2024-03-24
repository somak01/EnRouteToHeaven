#include<stdio.h>

int main() {
	printf("The size of different data types:\n");
	printf("char\t%d\n", sizeof(char));
	printf("signed char\t%d\n", sizeof(signed char));
	printf("short\t%d\n", sizeof(short));
	printf("unsigned short\t%d\n", sizeof(unsigned short));
	printf("int\t%d\n", sizeof(int));
	printf("unsigned int\t%d\n", sizeof(unsigned int));
	printf("long\t%d\n", sizeof(long));
	printf("unsigned long\t%d\n", sizeof(unsigned long));
	printf("long long int\t%d\n", sizeof(long long int));
	printf("unsigned long long int\t%d\n", sizeof(unsigned long long int));
	printf("float\t%d\n", sizeof(float));
	printf("double\t%d\n", sizeof(double));
	printf("long double\t%d\n", sizeof(long double));
	return 0;
}
