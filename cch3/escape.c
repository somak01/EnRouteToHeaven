#include<stdio.h>
#define MAXSIZE 1000
#define BACKSLASH '\\' 
/*converts escape characters into visible like tab to \t*/
void escape(char t[], char s[]);
void unescape(char t[], char s[]);
int main(){
	char test_string1[MAXSIZE] = {"nem tudom p\\ukk\t\n\n\r"};
	char test_string2[MAXSIZE];
	char test_string3[MAXSIZE];	
	printf("%s", test_string1);
	escape(test_string1, test_string2);
	printf("\n%s", test_string2);
	unescape(test_string2, test_string3);
	printf("\n%s", test_string3);
	return 0;
}

void escape(char t[], char s[]) {
	/*I have no patience to type in all the escape characters*/
	int c, i, j;
	i = j = 0;
	while (t[i] != '\0') {
		c = t[i];
		switch (c) {
			case (BACKSLASH): 
				s[j++] = BACKSLASH;
				s[j++] = BACKSLASH;
				break;
			case ('\t'):
				s[j++] = BACKSLASH;
				s[j++] = 't';
				break;
			case ('\n'):
				s[j++] = BACKSLASH;
				s[j++] = 'n';
				break;
			case ('\''):
				s[j++] = BACKSLASH;
				s[j++] = '\'';
				break;
			case ('\r'):
				s[j++] = BACKSLASH;
				s[j++] = 'r';
				break;
			case ('\a'):
				s[j++] = BACKSLASH;
				s[j++] = 'a';
				break;
			default:
				s[j++] = c;
				break;
		}
		++i;
	}
	s[j] = '\0';
}
					

void unescape(char t[], char s[]) {
	int c,  i,  j;
	i = j = 0;
	while (t[i] != '\0') {
		if (t[i] == '\\') {
			switch (t[++i]) {
				case 'n':
					s[j++] = '\n';
					break;
				case 't':
					s[j++] = '\t';
					break;
				case 'r':
					s[j++] = '\r';
					break;
				case 'a':
					s[j++] = '\a';
					break;
				case '\\':
					s[j++] = '\\';
					break;
				case '\'':
					s[j++] = '\'';
					break;
			}
		} else s[j++] = t[i];
		i++;
	}
	s[j] = '\0';
}
