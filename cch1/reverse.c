#include<stdio.h>
#define MAXSIZE 1000
void reverse(char*, int);
int get_line(char*, int);

int main() {
  int  len;
  char line[MAXSIZE];
  while ((len = get_line(line, MAXSIZE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }
  return 0;
}



int get_line(char* s, int limit) {
  int c, i;

  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}


void reverse(char* line, int len) {
  int l, r;
  l = 0;
  r = len - 2;
  while (l < r) {
    int tmp = line[r];
    line[r] = line[l];
    line[l] = tmp;
    ++l;
    --r;
  }
}
