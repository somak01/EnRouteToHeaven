#include<stdio.h>

double fahrToCels(int);
double celsToFahr(int);


int main() {
	int hex = 0xfafa;
	printf("%d\t%x\n", hex, hex);
	printf("Fahrenheit\tCelsius\n");
	for (int i = 0; i <= 300; i+=20) {
		printf("%6i\t\t%4.2f\n", i, fahrToCels(i));
	}
	return 0;
}


double fahrToCels(int fahrenheit) {
	//Calculates celsius from fahrenheit
	double celsius = (fahrenheit - 32.0) * (5.0 / 9);
	return celsius;
}

double celsToFahr(int celsius) {
	//Calculates fahrenheit from celsius
	double fahrenheit = (celsius / (5/9.0)) + 32;
	return fahrenheit;
}
