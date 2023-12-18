#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define RED_LIMIT 12
#define GREEN_LIMIT 13
#define BLUE_LIMIT 14

int main(int argc, char *argv[]) {
  puts("Let's go -- day 2 advent of code");

  char *content = NULL;
  FILE *f;
  size_t len = 0;
  ssize_t read;

  if (!argv[1]) {
    puts("specify full path file input");
    return 0;
  }

  f = fopen(argv[1], "r");
  if (!f) {
    perror("fopen");
    return 1;
  }
  const char delimiters[] = ":;,";
  int total = 0;

  while ((read = getline(&content, &len, f)) != -1) {
    char *token;

    token = strtok(content, delimiters);
    int gnum = 0;

    while (token != NULL) {

      if (strstr(token, "Game")) {
        gnum = atoi(&token[5]);
        total += gnum;
      }

      if (strstr(token, "red")) {
        if (atoi(&token[1]) > RED_LIMIT) {
          total -= gnum;
          break;
        }
      }
      if (strstr(token, "green")) {
        if (atoi(&token[1]) > GREEN_LIMIT) {
          total -= gnum;
          break;
        }
      }
      if (strstr(token, "blue")) {
        if (atoi(&token[1]) > BLUE_LIMIT) {
          total -= gnum;
          break;
        }
      }
      token = strtok(NULL, delimiters);
    }
  }

  printf("total %d\n", total);
  fclose(f);
  return 0;
}
