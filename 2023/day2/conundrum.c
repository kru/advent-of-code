#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/time.h"

#include "timer.h"

#define RED_LIMIT 12
#define GREEN_LIMIT 13
#define BLUE_LIMIT 14

const int STR_LEN = 200;

int main(int argc, char *argv[]) {
  puts("Let's go -- day 2 advent of code");

  char content[200];
  FILE *f;
  struct timeval start, end;

  gettimeofday(&start, NULL);
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

  while (fgets(content, STR_LEN, f) != NULL) {
    char *token;

    token = strtok(content, delimiters);
    int gnum = 0;

    while (token != NULL) {

      if (strstr(token, "Game")) {
        gnum = atoi(&token[5]);
        total += gnum;
      }

      if (strstr(token, "red") && atoi(&token[1]) > RED_LIMIT) {
        total -= gnum;
        break;
      }
      if (strstr(token, "green") && atoi(&token[1]) > GREEN_LIMIT) {
        total -= gnum;
        break;
      }
      if (strstr(token, "blue") && atoi(&token[1]) > BLUE_LIMIT) {
        total -= gnum;
        break;
      }
      token = strtok(NULL, delimiters);
    }
  }

  gettimeofday(&end, NULL);
  printf("total %d\n", total);
  printf("took: %.2f miliseconds\n", time_diff(start, end)/1000);
  fclose(f);
  return 0;
}
