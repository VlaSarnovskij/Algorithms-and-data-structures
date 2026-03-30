#include "Reelection.h"

void data_to_string(Reelection* r){
    printf("===== Initial Data =====\n");
    printf("N: %d, M: %d, S: %d\n", r->n, r->m, r->s);
    printf("Numbers: ");
    for (int i = 0; i < r->n; ++i) {
        printf("%d ", r->num[i]);
    }
    printf("\n\n");
}

int backtrack(Reelection* r) {
    // Success
    if (r->count == r->m) {
        if (r->current_sum == r->s) {
            printf("Combination found: ");
            for (int i = 0; i < r->m; ++i) {
                printf("%d ", r->path[i]);
            }
            printf("\n");

            // If we only need the first match, return 1 to stop
            if (r->mode == FIRST_MATCH) {
                return 1;
            }
        }
        return 0;
    }

    // Failure
    if (r->current_sum > r->s || r->index >= r->n) {
        return 0;
    }

    // Try adding numbers one by one
    for (int i = r->index; i < r->n; ++i) {
        Reelection next = *r; 
        
        next.path[next.count] = r->num[i]; 
        next.index = i + 1;               
        next.count = r->count + 1;        
        next.current_sum = r->current_sum + r->num[i]; 

        // 1 in return means stop
        if (backtrack(&next)) {
            return 1; 
        }
    }

    return 0;
}

void find_combinations(Reelection* r) {
    
    
}

void statistics_to_string(Reelection* r){
    printf("\n===== Statistics =====\n");
    printf("Total combinations to check: %lld\n", r->total_combinations);
    printf("Combinations checked: %lld\n", r->checked_combinations);
    printf("Progress: %.2f%%\n", r->total_combinations > 0 ? (double)r->checked_combinations / r->total_combinations * 100 : 0);
    printf("Search mode: ");
    switch (r->mode) {
        case FULL_SEARCH:
            printf("Full Search\n");
            break;
        case FIRST_MATCH:
            printf("First Match Search\n");
            break;
        case HEURISTIC:
            printf("Heuristic\n");
            break;
    }
    printf("\n");

}