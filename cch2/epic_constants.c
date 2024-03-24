#include<stdio.h>

//Some shit constants
#define SUM_NUM 1234 //this is an int
#define SUM_NUM2 123456789 //this is a long, also if we write 1234l or 1234L they are also longs

#define DBL_NUM 12313.123 //this is a double(and every floatin point numbr defined like this will be a double
#define FLT_NUM 1324.234f //however an f or F suffix will make it a float
#define BELL '\007'
#define HEX_BELL '\x7' // this should be the same as the octal BELL, and make an alarm sound or something

int main() {
	int dec = 31; //this is a decimal
	int oct = 037; //this 31 in octal form (8 base)
	int hex = 0x1F; //this is also 31 but in hexadecimal form(16 base)
	int bin = 0b11111; //this should also be 31 but in binary form

	printf("%d", (dec == oct && dec == hex && dec == bin));
	printf("\n%c", HEX_BELL);
	return 0;
}

