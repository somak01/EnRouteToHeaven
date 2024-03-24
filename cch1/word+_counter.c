#include<stdio.h>
#define IN 1
#define OUT 0

int main() {
	int c, word_count, character_count, newLine_count;
	word_count = character_count = newLine_count = 0;
	int in_word = OUT;

	while ((c = getchar()) != EOF) {
		++character_count;
		if (c == '\n'){
			++newLine_count;
		}
		if (c == '\n' || c == '\t' || c == ' ') {
			in_word = OUT;
		} else if (in_word == OUT) {
			in_word = IN;
			++word_count;
		}
	}	
	printf("The input has %d characters %d words and %d new lines\n",
			character_count, word_count, newLine_count);
	return 0;
}
