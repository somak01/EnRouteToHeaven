#include<stdio.h>
#define MAXLINE 1000l
#define END_OF_STRING '\0'
//char line[MAXLINE + 1];

int str_len(char s[]);
int main(){
	char line[MAXLINE + 1];
	printf("%d\n", str_len("baszdmeg"));
	printf("%c", line[0]);
	return 0;
}


int str_len(char s[]) {

	short i = 0;
	while (s[i] != END_OF_STRING) {
		++i;
	}
	return i;
}
