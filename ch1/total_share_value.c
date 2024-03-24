#include<stdio.h>

int main() {
	int num_of_shares_traded = 6000;
	float average_share_value = 32.12;

	printf("The total value of shares traded is: %.2f$", (average_share_value * num_of_shares_traded));
	return 0;
}
