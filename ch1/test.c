#include<stdio.h>

int power(int base, int power) {
    int res = 1;
    while (power > 0) {
        res *= base;
    }
    return res;
}


int main() {

    power(3, 4);
    return 0;
}