#include<stdio.h>
#define log(x) printf(#x " = %g\n", (double)x)
#define max(x, y) x > y ? x : y
#define swap(t, x, y) {t temp = x; x = y; y = temp;}
	
int main() {
	int x = 2;	
	double y = 1.12313;
	float z;
	z = 5.123131;
	log(x);
	swap(float, x, z);
	printf("%g", max(x, y));
	printf("\n%g", z);
	return 0;
}
