#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED_LIMIT 12
#define GREEN_LIMIT 13
#define BLUE_LIMIT 14

const int STR_LEN = 200;

int main(int argc, char **argv) {
    puts("day two part two");
    if (!argv[1]) {
        puts("please specify file location!");
        return 1;
    }

    FILE *f;
    char content[STR_LEN];
    struct timeval start, end;

    gettimeofday(&start, NULL);
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
        int minRed = 0, minGreen = 0, minBlue = 0;

        while (token != NULL) {
            if (strstr(token, "red")) {
                int r = atoi(&token[1]);
                if (r > minRed) {
                    minRed = r;
                }
            }
            if (strstr(token, "green")) {
                int g = atoi(&token[1]);
                if (g > minGreen) {
                    minGreen = g;
                }
            }
            if (strstr(token, "blue")) {
                int b = atoi(&token[1]);
                if (b > minBlue) {
                    minBlue = b;
                }
            }
            token = strtok(NULL, delimiters);
        }
        total += (minRed * minGreen * minBlue);
    }

    gettimeofday(&end, NULL);

    printf("total %d\n", total);
    fclose(f);
    printf("took %.2f miliseconds\n", time_diff(start, end));
    return 0;
}
