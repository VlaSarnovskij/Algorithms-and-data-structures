#include <string.h>
#include <stdlib.h>
#include "Reelection.h"

int main(int argc, char* argv[]) {
    // Basic usage check
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
        return 1;
    }

    char* input_file = NULL;

    Reelection r;
    
    // Set default values
    r.index = 0;
    r.count = 0;
    r.current_sum = 0;
    r.timeout_ms = -1; // -1 indicates no timeout
    
    // Basic argument parsing for the mode
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-mode") == 0 && i + 1 < argc) {
            if(strcmp(argv[i+1], "fullSearch") == 0) {
                r.mode = FULL_SEARCH;
            } else if (strcmp(argv[i+1], "firstMatchSearch") == 0) {
                r.mode = FIRST_MATCH;
            } else if(strcmp(argv[i+1], "heuristic") == 0) {
                printf("Heuristic mode is not implemented yet.\n");
                return 1;
            } else {
                fprintf(stderr, "Unknown mode: %s\n", argv[i+1]);
                return 1;
            }
            ++i;
        } else if (strcmp(argv[i], "-timeout") == 0 && i + 1 < argc) {
            r.timeout_ms = atoi(argv[++i]);
        } else {    
            input_file = argv[i];
        }
    }

    FILE *f;
    f = fopen(input_file, "r");
    if (!f) {
        fprintf(stderr, "Error: failed to open file %s\n", input_file);
        return 1;
    }
    if (fscanf(f, "%d %d %d", &r.n, &r.m, &r.s) != 3) {
        fprintf(stderr, "Error: failed to read N, M and S values.\n");
        if (f != stdin) fclose(f);
        return 1;
    }
    
    r.num = malloc(r.n * sizeof(int));
    for (int i = 0; i < r.n; ++i) {
        if (fscanf(f, "%d", &r.num[i]) != 1) {
            fprintf(stderr, "Error: failed to read number %d.\n", i + 1);
            if (f != stdin) {
                fclose(f);
            }
            return 1;
        }
    }

    r.path = malloc(r.m * sizeof(int));
    
    data_to_string(&r);
    backtrack(&r);
    statistics_to_string(&r);

    // Clean up memory
    free(r.num);
    free(r.path);
    
    return 0;
}