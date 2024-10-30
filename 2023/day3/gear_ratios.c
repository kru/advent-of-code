#include <stdio.h>
#include <string.h>

const char symbols[] = "*#+$";

int sym_len = sizeof(symbols) / sizeof(symbols[0]);

int is_symbol(char x) {
    for (int i = 0; i < sym_len; i++) {
        if (symbols[i] == x) {
            return 1;
        }
    }
    return -1;
}

/**
 * NOTE: if symbol found in current line, check prevline and nextline
 * prevline[current_idx - 1], prevline[current_idx], prevline[current_idx+1]
 * nextline[current_idx - 1], nextline[current_idx], nextline[current_idx+1]
 */
int main(int argc, char **argv) {
    puts("day 3 part one");
    if (!argv[1]) {
        puts("please specify file location!");
        return 1;
    }

    FILE *f;
    char *content = NULL;
    size_t len = 0;
    ssize_t read;

    f = fopen(argv[1], "r");

    if (!f) {
        perror("fopen");
        return 1;
    }

    char *prevline = NULL;
    char *nextline = NULL;

    int cur_line_idx = 0;
    int total = 0;
    while ((read = getline(&content, &len, f)) != -1) {
        cur_line_idx++;
        int j = strlen(content);
        printf(" len: %d, content: %s\n", j, content);

        for (int i = 0; i < j; i++) {
            if (content[i] == '.') {
                continue;
            }

            if (is_symbol(content[i]) == 1) {
            }
        }
    }

    printf("total %d\n", total);
    fclose(f);
    return 0;
}
