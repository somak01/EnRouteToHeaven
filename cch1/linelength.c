#include<stdio.h>
#define MAX_SIZE 1000


int get_line(char*, int);
void copy(char*, char*);


int main() {
  int len, longest;
  char line[MAX_SIZE];
  char longest_line[MAX_SIZE];

  longest = 0;

  while ((len = get_line(line, MAX_SIZE)) > 0){
    if (len > longest) {
      copy(line, longest_line);
      longest = len;
    }
  }

  if (longest > 0) {
    printf("The longest line is \"%s\"", longest_line);
  }
  return 0;
}

int get_line(char* line, int max_len) {
  int c, i;
  for (i = 0; i < max_len && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(char* from, char* to) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
