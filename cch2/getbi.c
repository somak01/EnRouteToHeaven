#include<stdio.h>


unsigned getbits(unsigned x, short p, short n);
unsigned setbitc(unsigned x, short p, short n, unsigned y);
unsigned invert(unsigned x, short p, short n);
int main() {
	unsigned num = 0b00111011;
	unsigned res = getbits(num, 3, 3);
	setbitc(num, 5, 3, 0);
	invert(num, 7, 3);
	return 0;
}


unsigned getbits(unsigned x, short p, short n) {
	return (x>>(p+1-n)) & ~(~0 << n);
}

unsigned int setbitc(unsigned int x, short p, short n, unsigned int y) {
	unsigned int mask = ~(~0 << n) << (p + 1 - n);
	x &= ~mask;
	y = getbits(y, n, n);
	y = y << (p+1-n);
	return x | y;
}

unsigned invert(unsigned x, short p, short n) {
	unsigned mask = ~(~0 << n);
	unsigned mask2 = ~(~(~0 << n) << (p+1 -n));
	unsigned y = getbits(x, p, n);
	y = ~y;
	y &= mask;
	y = y << (p+1 -n);
	x &= mask2;
	printf("%b",x|y);
	return 0;
	

}
