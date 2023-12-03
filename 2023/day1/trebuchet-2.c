#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *f;
  char content[101];
  int size_t = 100;
  int total = 0;

  printf("first arg %d, second arg %s\n", argc, argv[2]);

  f = fopen(argv[1], argv[2]);
  if (f == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(content, size_t, f) != NULL) {
    printf("\n%s\n", content);
    int i = 0;
    char firstlast[2] = "";
    while (content[i]) {
      if (atoi(&content[i]) != 0 && strlen(firstlast) == 0) {
        strncat(firstlast, &content[i], 1);
      }
      i++;
    }
    for (int j = i - 2; j >= 0; j--) {
      if (atoi(&content[j]) != 0 && strlen(firstlast) == 1) {
        strncat(firstlast, &content[j], 1);
      }
    }
    if (strlen(firstlast) < 2) {
      perror("to small");
      return EXIT_FAILURE;
    }
    int tmp = atoi(firstlast);
    if (tmp > 0) {
      total += tmp;
    }
  }
  printf("res: %d\n", total);
  fclose(f);
  return EXIT_SUCCESS;
}
