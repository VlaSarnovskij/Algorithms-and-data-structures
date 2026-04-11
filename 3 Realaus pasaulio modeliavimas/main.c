#include <stdio.h>    // Для printf
#include <string.h>
#include <stdlib.h>
#include "simulation.h" 
#include "priorityQueue.h" // 1lugu2023
#include "BigInteger.h" // 1masi2289

int main(int argc, char* argv[]) {
    printf("KaskoSim - Simuliatorius automobiliu draudimo apskaiciavimui\n");

    char* filename = malloc(256);
    if (argc > 1 && argv[1] != NULL) {
        filename = argv[1];
    } else {
        int i = 0;
        while (argv[0][i] != '\0' && i < 255) {
            filename[i] = argv[0][i];
            ++i;
        }
        filename[i] = '\0';
        filename[--i] = 'g';
        filename[--i] = 'f';
        filename[--i] = 'c';
        filename[--i] = '.';
    }
    printf("Filename: %s\n", filename);
    SimulationParams params;

    readParamsFromFile(filename, &params);
    
    SimulationResult withVip = simulate(params, 30, 1);

    //SimulationResult withoutVip = simulate(params, 30, 0);

    //printf("Diff: %ld\n", withVip.total_profit - withoutVip.total_profit);

    return 0;
}