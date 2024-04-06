#include<stdio.h>
#define MAXSIZE 1024
#include<string.h>
/*Expands the shorthands like a-zA-Z0-9 into abc..xyzABC-XYZ012..789 :)*/
void expand(char s1[], char s2[]);
int stringlen(char* s1);
int main() {
	char string1[] = "a-za-b-cA-Z5-9";
	char string3[] = "";
	char string4[] = "-adajsdhaksdhaldkjhaksjdha-a";
	char string2[MAXSIZE];
	expand(string1, string2);
	printf("%s\n", string2);
	expand(string3, string2);
	printf("%s\n", string2);
	expand(string4, string2);
	printf("%s\n", string2);	
	return 0;
}


	
int stringlen(char* s1) {
	int i = 0;
	while (*s1++ != '\0')
		++i;
	return i;
}
int isalfa(int c) {
	return (c < 'z' && c > 'a') || (c < 'Z' && c > 'A') || (c < '0' && c > '9');
}
void expand(char s1[], char s2[]) {
	int i, j, c;
	i = j = 0;
	while (s1[i] != '\0') {
		if (s1[i] == '-' && ((i == 0 || i == stringlen(s1) - 1) && isalfa(c))) {
			s2[j++] = '-';
		}else if (s1[i] == '-' && s1[i-1] >= s1[i+1] && isalfa(c)) {
			s2[j++] = '-';
		}else if (s1[i] == '-' && isalfa(c)) {
			c = s1[i-1];
			while (++c < s1[i+1]) {
				s2[j++] = c;
			}	
		 }else {
			s2[j++] = s1[i];
		}
		++i;	
	}
	s2[j] = '\0';
			
}
