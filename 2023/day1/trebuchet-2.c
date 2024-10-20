#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *chars[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
};
char nums[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int char_len = sizeof(chars) / sizeof(chars[0]);
int str_to_int(char *str) {
    for (int i = 0; i < char_len; i++) {
        if (strcmp(str, chars[i]) == 0) {
            return i + 1;
        }
    }

    return -1;
}

int n_len = sizeof(nums) / sizeof(nums[0]);
int char_to_int(char x) {
    for (int i = 0; i < n_len; i++) {
        if ((nums[i] == x) == 1) {
            return i;
        }
    }
    return -1;
}

void pick_n_char(int n, int start_idx, char *str, char *lineptr) {
    int i = 0;
    while (i < n) {
        str[i] = lineptr[start_idx + i];
        i++;
    }
}

void clean_n_char(int n, char *str) {
    int i = 0;
    while (i < n) {
        str[i] = '\0';
        i++;
    }
}

struct CharNum {
    char str3[3];
    char str4[4];
    char str5[5];
} CharNum;

// answer 55614
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

    int first = 0;
    int last = 0;
    int total = 0;

    struct CharNum *charnum = &CharNum;
    while ((read = getline(&lineptr, &n, f)) != -1) {
        printf("lineptr: %s\n", lineptr);
        int j = strlen(lineptr);

        for (int i = 0; i < j; i++) {
            char c = lineptr[i];
            int r = char_to_int(c);
            if (first == 0 && r != -1) {
                first = r;
            }
            if (r != -1) {
                last = r;
            }

            pick_n_char(3, i, charnum->str3, lineptr);
            int r3 = str_to_int(charnum->str3);
            if (first == 0 && r3 != -1) {
                first = r3;
            }
            if (r3 != -1) {
                last = r3;
            }
            // printf("\nidx: %d 3, %s ", i, charnum->str3);
            clean_n_char(3, charnum->str3);

            pick_n_char(4, i, charnum->str4, lineptr);
            int r4 = str_to_int(charnum->str4);
            if (first == 0 && r4 != -1) {
                first = r4;
            }
            if (r4 != -1) {
                last = r4;
            }
            // printf("\nidx: %d 4, %s ", i, charnum->str4);
            clean_n_char(4, charnum->str4);

            pick_n_char(5, i, charnum->str5, lineptr);
            int r5 = str_to_int(charnum->str5);
            if (first == 0 && r5 != -1) {
                first = r5;
            }
            if (r5 != -1) {
                last = r5;
            }
            // printf("\nidx: %d 5, %s ", i, charnum->str5);
            clean_n_char(5, charnum->str5);
        }
        // printf("first: %d, last: %d\n", first, last);
        total += (first * 10) + last;

        first = 0;
        last = 0;
    }
    printf("\ntotal: %d\n", total);
    // in mac os to see memory leaks -> ps aux | grep program_name -> leaks program_name
    // fscanf(stdin, "c");
    return EXIT_SUCCESS;
}
