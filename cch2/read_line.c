#include<stdio.h>
#define MAXSIZE 1000


int read_line(char string[], int size);

int main() {
	char line[MAXSIZE];
	read_line(line, MAXSIZE);
	printf("%s", line);
	return 0;
}

int read_line(char s[], int size) {
	char c;
	int i;
	for (i = 0; (i < size-1) == ((c=getchar()) != '\n') == (c != EOF) == 1; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;	
}
