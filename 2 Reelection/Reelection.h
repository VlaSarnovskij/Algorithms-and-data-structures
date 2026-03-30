#ifndef REELECTION_H
#define REELECTION_H

#include <stdio.h>

typedef enum {
    FULL_SEARCH,
    FIRST_MATCH,
    HEURISTIC
} Mode;

typedef struct {
    int n, m, s;
    int* num;        

    int* path;       // Selected numbers in the current path
    int index;       // Start index
    int count;       // How many numbers are in the path
    int current_sum;  

    Mode mode;
    int timeout_ms;  // Timeout in milliseconds

    long long total_combinations; // Total combinations to check
    long long checked_combinations; // Combinations checked so far
} Reelection;

void data_to_string(Reelection* r);
int backtrack(Reelection* r); // Returns 1 if we should stop searching
void statistics_to_string(Reelection* r);
#endif
