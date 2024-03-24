#include<stdio.h>
#define MAXSIZE 1000
int max;
char line[MAXSIZE];
char longest_line[MAXSIZE];

int get_line(void);
void copy(void);

int main() {
  int len;
  extern int max;
  extern char longest_line[];

  max = 0;

  while ((len = get_line()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0) {
    printf("%s", longest_line);
  }
  

  return 0;

}



int get_line(void) {
  extern char line[];
  int c, i;

  for (i = 0; i < MAXSIZE && (c = getchar()) != EOF && c != '\n';++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy(void) {
  int i;
  extern char line[], longest_line[];

  i = 0;
  while ((longest_line[i] = line[i]) != '\0') {
    ++i;
  }
}
