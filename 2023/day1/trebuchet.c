#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// answer is 55488
int main() {
  FILE *f;

  char *content = NULL;
  int calibration = 0;
  size_t len = 0;
  ssize_t read;

  printf("Hei there, just starting advent of code this year\n");

  f = fopen("2023/day1/input", "r");
  if (!f) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while ((read = getline(&content, &len, f)) != -1) {
    int i = 0, j = strlen(content) - 1;
    char firstLast[2] = "";
    while (i <= j) {
      if (atoi(&content[i]) != 0) {
        strncat(firstLast, &content[i], 1);
        break;
      }
      i++;
    }

    while (j >= 0) {
      if (atoi(&content[j]) != 0) {
        strncat(firstLast, &content[j], 1);
        break;
      }
      j--;
    }
    int res = atoi(firstLast);
    // make sure firstLast is two digits
    if (sizeof(firstLast) < 2) {
      perror("something off!");
      return EXIT_FAILURE;
    }
    if (res != 0) {
      calibration += res;
    }
  }

  printf("Result: %d\n", calibration);
  fclose(f);
  return EXIT_SUCCESS;
}
