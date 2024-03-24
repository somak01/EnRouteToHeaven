#include<stdio.h>
#define MAXSIZE 1000
#define IN 1
#define OUT 0
int get_stripped_line(char*, int);


int main() {
  int len;
  char line[MAXSIZE];


  while ((len = get_stripped_line(line, MAXSIZE))>0) {
    printf("%s", line);
  }


  return 0;

}


int get_stripped_line(char* line, int limit) {
  int state,c,i;
  state = OUT;

  for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n';) {
    if (state && c == ' ' || c == '\t') {
      state = OUT;
      line[i] = c;
      ++i;
	}
    else if (c != ' ' &&  c != '\t') {
      state = IN;
      line[i] = c;
      ++i;
    }
  }

  if (c == '\n' && state ) {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
