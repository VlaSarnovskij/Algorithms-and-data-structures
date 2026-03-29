#ifndef REELECTION_H
#define REELECTION_H

#include <stdio.h>

typedef enum {
    FULL_SEARCH,
    FIRST_MATCH,
    HEURISTIC
} Mode;

typedef struct {
    int* num;
    int n, m, s;

    int* path;       // Selected numbers in the current path
    int index;       // Start index
    int count;       // How many numbers are in the path
    int current_sum;  

    Mode mode;
    int timeout_ms;  // Timeout in milliseconds
} Reelection;

int backtrack(Reelection r); // Returns 1 if we should stop searching

#endif
