#include<stdint.h>
#include<stdio.h>
#include<limits.h>
#include<float.h>

int main() {
	printf("the range of short is %d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("the range of ushort is %d - %d\n", 0, USHRT_MAX);
	printf("the range of char is %d - %d\n", CHAR_MIN, CHAR_MAX);
	printf("the range of uchar is %d - %d\n",0,  UCHAR_MAX);
	printf("the range of int is %d - %d\n", INT_MIN, INT_MAX);
	printf("the range of uint is %u - %u\n", 0, UINT_MAX);
	printf("the range of long is %ld - %ld\n", LONG_MIN, LONG_MAX);
	printf("the range of ulong is %lu - %lu\n", 0UL, ULONG_MAX);
	printf("the range of float is %f - %f\n", FLT_MIN, FLT_MAX);
	printf("the range of double is %f - %f\n", DBL_MIN, DBL_MAX);
	printf("the range of long double is %Lf - %Lf\n", LDBL_MIN, LDBL_MAX);
	return 0;
}
