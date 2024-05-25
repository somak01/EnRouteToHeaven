#include<stdio.h>

double power(int base, int power) {
	double val = 1.0;
	for (int i = 0; i < power; i++) {
		val *= base;
	}
	return val;
}
