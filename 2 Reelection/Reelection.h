#ifndef REELECTION_H
#define REELECTION_H

#include <stdio.h>

typedef enum Mode {
    FULL_SEARCH,
    FIRST_MATCH,
    HEURISTIC
};

typedef struct Reelection {
    int* num;
    int n, m, s;
}

#endif
