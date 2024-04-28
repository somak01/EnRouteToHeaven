#include<stdio.h>
#include<string.h>
#define MAXSIZE 500
/*Prints only those lines that contain the pattern given
 * the lines shouldn't be too long*/
int	is_pattern_present(char[], char[], int); 
int getLine(char[]);
int strindex(char[], char[]);
/*the same as strindex just from the right side*/

int r_strindex(char[], char[]);

char pattern[] = "ould";
int main() {
	char line[MAXSIZE];
	int idx;

	while (getLine(line)) {
		/*if (is_pattern_present(line, pattern, strlen(line))
			printf("%s", line);
		*/
		if ((idx = r_strindex(line, pattern))>= 0) {
			printf("%s", line);	
			printf("%d\n", idx);
		}
	}			
	return 0;
}
	
int getLine(char line[]) {
	int i, c;
	for (i = 0; (c = getchar()) != '\n' && c != '\0' && c != EOF; i++) {
		line[i]  = c;
	}
	if (c == '\n') line[i++] = c;
	line[i] = '\0';
	return i;
}

int is_pattern_present(char line[], char pattern[], int size) {
	int i, c;
	i = 0;
	while ((c = line[i]) != '\0') {
		if ( c == pattern[0]) {
			int k = 0;
			while (k < strlen(pattern) && i < size
					 && pattern[++k] == line[++i]) {
						;
			}
			if (k == strlen(pattern)) {
				return 1;
			} 
		}
		i++;
	} return 0;
}

int strindex(char line[], char pattern[]) {
	int i, j, k, c;
	for (i = 0; line[i] != '\0'; i++) {
		for (j = i, k = 0; line[j] == pattern[k]; k++, j++){
			;
		} if (k > 0 && pattern[k] == '\0') return i;
	
	}
	return -1;
}	

int r_strindex(char line[], char pattern[]) {
	int i, j , k, c;
	for (i = strlen(line) - 1; i >= 0; i--) {
		for (j = i, k = strlen(pattern) - 1; line[j] == pattern[k] && j >= 0 && k >= 0; k--, j--) {
			if (k == 0) {
				return j;
			}	
		}	
	}
	return -1;
}
