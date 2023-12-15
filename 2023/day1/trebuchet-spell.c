#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("lets go part two\n");
  FILE *f;
  f = fopen("input", "r");

  if (!f) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char *lineptr = NULL;
  size_t n = 0;
  ssize_t read;
  long int total = 0;
  int lineNum = 0;

  while ((read = getline(&lineptr, &n, f)) != -1) {
    ++lineNum;
    int i = 0, j = strlen(lineptr);
    char fl[10] = "";
    char tmp[2] = "";

    char str1[1] = "";
    char str3[4] = "";
    char str4[5] = "";
    char str5[6] = "";

    char firstLast[3] = "";
    for (; i < j; i++) {
      // if a string number then append to fl then continue
      int num = atoi(&lineptr[i]);
      if (num != 0) {
        snprintf(tmp, 2, "%d", num);
        strcat(fl, tmp);
        if (strlen(str1) > 0) {
          memset(str1, '\0', strlen(str1));
        }
        continue;
      }

      int ln = 3;
      strncat(str3, &lineptr[i], ln);
      if (strlen(str3) == 3) {
        if (strcmp(str3, "one") == 0) {
          strcat(fl, "1");
          memset(str3, '\0', strlen(str3));
          continue;
        } else if (strcmp(str3, "two") == 0) {
          strcat(fl, "2");
          memset(str3, '\0', strlen(str3));
          continue;
        } else if (strcmp(str3, "six") == 0) {
          strcat(fl, "6");
          memset(str3, '\0', strlen(str3));
          continue;
        }
        memset(str3, '\0', strlen(str3));
      }

      int lnf = 4;
      if (strlen(str4) == 3) {
        lnf = 1;
      }
      strncat(str4, &lineptr[i], lnf);
      if (strlen(str4) == 4) {
        if (strcmp(str4, "four") == 0) {
          strcat(fl, "4");
          memset(str4, '\0', strlen(str4));
          continue;
        } else if (strcmp(str4, "five") == 0) {
          strcat(fl, "5");
          memset(str4, '\0', strlen(str4));
          continue;
        } else if (strcmp(str4, "nine") == 0) {
          strcat(fl, "9");
          memset(str4, '\0', strlen(str4));
          continue;
        }
        memset(str4, '\0', strlen(str4));
      }

      int lnfi = 5;
      if (strlen(str5) == 4) {
        lnfi = 1;
      }
      strncat(str5, &lineptr[i], lnfi);

      if (strlen(str5) == 5) {
        if (strcmp(str5, "three") == 0) {
          strcat(fl, "3");
          memset(str5, '\0', strlen(str5));
          continue;
        } else if (strcmp(str5, "seven") == 0) {
          strcat(fl, "7");
          memset(str5, '\0', strlen(str5));
          continue;
        } else if (strcmp(str5, "eight") == 0) {
          strcat(fl, "8");
          memset(str5, '\0', strlen(str5));
          continue;
        }
        memset(str5, '\0', strlen(str5));
      }
    }

    firstLast[0] = fl[0];
    firstLast[1] = fl[(strlen(fl) - 1)];
    firstLast[2] = '\0';
    total += atoi(firstLast);
  }
  printf("\ntotal: %ld\n", total);
  return EXIT_SUCCESS;
}
