#include<stdio.h>


int main() {
	int c, blanks, tabs, new_lines;
	blanks = tabs = new_lines = 0;

	while  ((c = getchar()) != EOF) {
		if (c == ' '){ ++blanks;}
		else if (c == '\t'){ ++tabs;}
		else if (c == '\n') {++new_lines;}
	}


	printf("There were %d blanks %d tabs and %d new lines\n", 
						blanks, tabs, new_lines);

	return 0;
}
