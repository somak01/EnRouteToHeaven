#include<stdio.h>
#define MAXSIZE 1000

int get_line(char* line, int limit);

int main() {
  int len;

  char line[MAXSIZE];

  while ((len = get_line(line, MAXSIZE)) > 0) {
    if (len > 80) {
      printf("%s", line);
    }
  }
  return 0;
}



int get_line(char* line, int limit) {
  int c, i;

  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  return i;

}
