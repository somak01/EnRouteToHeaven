#include<stdio.h>

int htoi(char s[]);

int main() {
	printf("%d\n", htoi("0x1f"));
	printf("%d\n", htoi("ffff"));
	printf("%d\n", htoi("0xFABCDE"));
	return 0;
}


int htoi(char s[]) {
	int num,i, j;
	num = 0;
	i = 0;
	j = 0;
	if (s[0] == '0'){
		for (i = 0; s[i] == '0' || s[i] == 'x' || s[i] == 'X'; ++i) {
			j = i;
		
		}
		++j;
	}
	for (i = j; (s[i] <= 'f' &&  s[i] >= 'a') || (s[i] <= 'F' && s[i] >= 'A') || (s[i] >= '0' && s[i] <= '9'); ++i) {
		int curr_dig;
		if (s[i] >= '0' && s[i] <= '9') {
			curr_dig = s[i] - '0';
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			curr_dig = s[i] - 'A' + 10;
		} else {
			curr_dig = s[i] - 'a' + 10;
		}
		num = 16 * num + curr_dig;
	}
	return num;
}
	

