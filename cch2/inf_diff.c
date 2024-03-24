#include<stdio.h>


#define MAXSIZE 1000
#define END_OF_LINE '\n'


int get_line(char s[], int limit);
void squeeze(char s[], int  c);
void strcatt(char s[], char t[]);
void squeeze2(char s1[], char s2[]);
int any(char s1[], char s2[]);
int main() {
	int nums[] = {1, 2, 3, 4, 5};
	int i = 0;
	int j = 0;
	char line[MAXSIZE];
	char shiet[MAXSIZE] = "hogy mondjam el hogy vagyom rad mivan?\0";
//	squeeze(shiet, 'o');
	get_line(line, MAXSIZE);
	printf("\n%d\n", any(shiet, line));
	squeeze2(shiet, line);
	printf("%s", shiet);
	//printf("\n%d  %d", nums[++i], nums[j++]);//Supposed to be 2 and 1
	return 0;
}

void squeeze(char s[], int c) {
	int i, j;
	for (j = i = 0; s[i] != '\0'; ++i) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}	

int get_line(char s[], int limit) {
	char c;
	int i;
	for (i = 0; i < MAXSIZE-1 && (c = getchar()) != END_OF_LINE && c  != EOF; ++i) {
		s[i] = c;
	}
	if (c == END_OF_LINE) {
		s[i++] = c;
	}
	s[i] = '\0';
	
	return i;
}


void strcatt(char s[], char t[]) {
/*naive version concatenates the 2 string
puts t to the end of s, it expects s to have enough space to hold both itself and t*/
	int i, j;
	i = j = 0;
	while (s[i] != '\0') {
		++i;
	}
	while (t[j] != '\0') {
		s[i++] = t[j++];
	}
}
			

void squeeze2(char s1[], char s2[]) {
	int i, j, k;
	for (i = 0; s2[i] != '\0'; ++i) {
		for (j = k = 0; s1[j] != '\0'; ++j) {
			if (s1[j] != s2[i]) {
				s1[k++] = s1[j];
			}
		}	
		s1[k] = '\0';
	}
}
			

int any(char s1[], char s2[]) {
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
					return i;
			}
		}
	}
	return -1;
}
