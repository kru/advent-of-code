#include <stdio.h>
#include <string.h>

int main() {
  char tc[4] = "";
  tc[0] = 't';
  tc[1] = 'w';
  tc[2] = 'o';
  tc[3] = '\0';

  int r = strcmp(tc, "two");
  printf("res %d", r);
}
