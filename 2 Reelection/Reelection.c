#include "Reelection.h"

int backtrack(Reelection r) {
    // Success
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

    // Failure
    if (r.current_sum > r.s || r.index >= r.n) {
        return 0;
    }

    // Try adding numbers one by one
    for (int i = r.index; i < r.n; ++i) {
        Reelection next = r; 
        
        next.path[next.count] = r.num[i]; 
        next.index = i + 1;               
        next.count = r.count + 1;        
        next.current_sum = r.current_sum + r.num[i]; 

        // 1 in return means stop for FIRST_MATCH mode
        if (backtrack(next)) {
            return 1; 
        }
    }

    return 0;
}