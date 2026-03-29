#include "Reelection.h"

int backtrack(Reelection r) {
    // 1. Success condition: we have picked M numbers
    if (r.count == r.m) {
        if (r.current_sum == r.s) {
            printf("Found: ");
            for (int i = 0; i < r.m; ++i) {
                printf("%d ", r.path[i]);
            }
            printf("\n");

            // If we only need the first match, return 1 to stop
            if (r.mode == FIRST_MATCH) {
                return 1;
            }
        }
        return 0;
    }

    // 2. Failure condition: sum exceeded or no more numbers to pick
    if (r.current_sum > r.s || r.index >= r.n) {
        return 0;
    }

    // 3. Recursive step: try adding numbers one by one
    for (int i = r.index; i < r.n; ++i) {
        // Create the next state based on the current one
        Reelection next = r; 
        
        next.path[next.count] = r.num[i]; // Pick the number
        next.index = i + 1;               // Move to the next index for the next call
        next.count = r.count + 1;         // Increment picked count
        next.current_sum = r.current_sum + r.num[i]; // Update sum

        // 1 in return means stop for FIRST_MATCH mode
        if (backtrack(next)) {
            return 1; 
        }
    }

    return 0;
}