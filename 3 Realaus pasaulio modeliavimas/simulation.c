#include "simulation.h"
#include <stdio.h>

void readParamsFromFile(const char* filename, SimulationParams* params){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        
    }

    int* fields[] = {
        &params->A, &params->A1, &params->U,
        &params->K, &params->T1, &params->T2
    };

    char line[256];

    for (int i = 0; i < 6; i++) {
        if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d", fields[i]);
        }
    }

    fclose(file);
}

SimulationResult simulate(SimulationParams params, int days, int hasContracts){
    printf("Simuliacija paleista su parametrais: A=%d, A1=%d, U=%d, K=%d, T1=%d, T2=%d\n", 
        params.A, params.A1, params.U, params.K, params.T1, params.T2);

    SimulationResult result;
    

    
    return result;
}