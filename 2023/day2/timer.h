#include <sys/time.h>

double time_diff(struct timeval start, struct timeval end) {
    double start_ms = (double)start.tv_sec * 1000000 + (double)start.tv_usec;
    double end_ms = (double)end.tv_sec * 1000000 + (double)end.tv_usec;
    return end_ms - start_ms; // Returns difference in microseconds
}
