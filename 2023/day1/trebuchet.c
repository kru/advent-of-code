#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Result {
    int first;
    int last;
    int total;
} Result;

char nums[] = {'0', '1', '2', '3', '4','5','6','7','8','9'};

int n_len = sizeof(nums)/sizeof(nums[0]);

int char_to_int(char x) {
  for (int i = 0; i < n_len; i++) {
    if ((nums[i] == x) == 1) {
      return i;
    }
  }
  return -1;
}

// answer is 55488
int main() {
    FILE *f;

    char *content = NULL;
    size_t len = 0;

    f = fopen("input", "r");
    if (!f) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct Result result = Result;
    result.first = 0;
    result.last = 0;
    result.total = 0;

    while (getline(&content, &len, f) != -1) {
        // printf("\ncontent: %s\n", content);
        int i = 0;
        while (content[i] != '\0') {
            char c = content[i];
            int r = char_to_int(c);
            // printf("idx: %d, %c val: %d \n", i, c, char_to_int(c));
            if (result.first == 0 && r != -1) {
                result.first = r;
            }

            if (r != -1) {
                result.last = r;
            }
            i++;
        }

        result.total += (result.first * 10) + result.last;
        // printf("first: %d, last: %d, total: %d\n", result.first, result.last, result.total);

        result.first = 0;
        result.last = 0;
    }

    printf("\nResult: %d\n", result.total);
    fclose(f);
    return EXIT_SUCCESS;
}
