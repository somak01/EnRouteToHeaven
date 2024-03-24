#include<stdio.h>
int power(int, int);
int main() {
  int a = 5, b = 0;
  printf("The result of putting %d to the power of %d is %d", a, b, power(a,b));
  return 0;
}



int power(int base, int exponent) {
  int res = 1;
  for (int i =0; i < exponent; ++i) {
    res *= base;
  }
  return res;
}
