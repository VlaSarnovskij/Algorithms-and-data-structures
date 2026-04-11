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
    // Check for timeout
    if (r->timeout_ms != -1) {
        double elapsed = (double)(clock() - r->start_clock) / CLOCKS_PER_SEC * 1000.0;
        if (elapsed >= r->timeout_ms) {
            printf("Timeout reached!\n");
            return 1; // Stop signal
        }
    }

    // Success
    if (r->count == r->m) {
        r->checked_combinations++;

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

    int start_from = r->index;

    for (int i = start_from; i < r->n; ++i) {
        r->path[r->count] = r->num[i];
        r->current_sum += r->num[i];
        r->count++;
        r->index = i + 1; // Start from the next element

        if (backtrack(r)) {
            return 1; // Catch stop signal
        }

        // Step Back
        r->count--;
        r->current_sum -= r->num[i];
    }
    // Reset index
    r->index = start_from; 

    return 0;
}

void find_total_combinations(Reelection* r) {
    if (r->m < 0 || r->m > r->n) {
        r->total_combinations = 0;
        return;
    }
    if (r->m == 0 || r->m == r->n) {
        r->total_combinations = 1;
        return;
    }

    if (r->m > r->n/2) r->m = r->n - r->m;

    long long total_comb = 1;
    for (int i = 1 ; i <= r->m ; i++) {
        total_comb = total_comb * (r->n - i + 1) / i;
    }
    r->total_combinations = total_comb;
}

void statistics_to_string(Reelection* r){
    find_total_combinations(r);

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
