#include <stdio.h>

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
    }  
    

    return 0;
}