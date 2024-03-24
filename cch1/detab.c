#include<stdio.h>
/*My logic since we keep track of the distance, everytime we encounter a tab
instead of the tab we will put i % 8 blanks, that seems about right, because
tabs are 8 characters long, and if we hit it when we typed something in
like "ate\t" then it will last until the eighth character so it will be 
5 char long*/


int main() {
  int c, i, j;
  i = 0;
  

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      putchar(c);
      i = 0;
    } else if(c == '\t') {
      
      for (j = 0; j < 8 - (i % 8); j++) putchar(' ');
      i+= 8 - i % 8;

    } else {
      putchar(c);
      ++i;
    }
  }
  return 0;
}

