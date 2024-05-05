#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
#define EXIT 0

void printd(int num); 
void r_itoa(int num, char num_text[], int idx);
void r_reverse(char text[], int left, int right);
	

int main() {
	char num_text[MAXSIZE];
	char xd[] = "alugy";
	r_reverse(xd, 0, strlen(xd)-1);
	printf("%s\n", xd);
	r_itoa(0, num_text, 0);
	printf("%s", num_text);
	return EXIT;	
}

void r_itoa(int num, char num_text[], int idx) {
	if (num/10)  {
		num_text[idx++] = abs(num % 10) + '0';
		r_itoa(num/10, num_text, idx);
	}
	else {
	num_text[idx++] = abs(num % 10) + '0';
	if (num < 0) num_text[idx++] = '-';
	num_text[idx] = '\0';
	r_reverse(num_text, 0, strlen(num_text)-1);
}

	
}

void printd(int num) {
	if (num/10) {
		printd(num/10);
} 
	printf("%c", num % 10 + '0');
		
}

void r_reverse(char text[], int left, int right) {
	if (left < right) {
		int tmp = text[left];
		text[left] = text[right];
		text[right] = tmp;
		r_reverse(text, left+1, right-1);
	}

} 
