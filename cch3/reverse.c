#include<stdio.h>
#define MAXSIZE 1024
#define size(x) sizeof(x)/sizeof(x[0])
void reverse(char s[], int n);/*reverses the string in-place*/

int main() {
	char s[] = "Hakapeszi Maki ha kap eszi";
	reverse(s, size(s)-1);
	printf("%s", s);
	return 0;
}

void reverse(char s[], int n) {
	int c, i, j;
	for (i = 0, j = n - 1; i < j; i++, j--) {
		c = s[i];
		printf("valami tortenik geci?\n");
		s[i] = s[j];
		s[j] = c; 
	}
}
