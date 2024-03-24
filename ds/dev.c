#include<stdio.h>

#define NUMELEMENTS 100

void average();
int main() {
	average();
	return 0;
}


void average() {
	int  nums[NUMELEMENTS];
	int i, total;	
	float average;
	total = 0;

	for (i = 0; i < NUMELEMENTS; ++i) {
		scanf("%d", &nums[i]);
		total += nums[i];
	}

	average = total / NUMELEMENTS;
	printf("\nnumber of difference:");
	for (int i = 0; i < NUMELEMENTS; ++i) {
		printf("\n%.3f", average - nums[i]);
	}
}
