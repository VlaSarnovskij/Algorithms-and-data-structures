#include <stdio.h>
#include <time.h>    
#include <stdlib.h>
#include "simulation.h" 
#include "priorityQueue.h" // 1lugu2023
#include "BigInteger.h" // 1masi2289


int main(int argc, char* argv[]) {
    printf("KaskoSim - Simuliatorius automobiliu draudimo apskaiciavimui\n\n");

    int seed = (int)time(NULL);
    char filename[256] = "";    
    int custom_seed = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-rnd") == 0 && i + 1 < argc) {
            seed = atoi(argv[++i]);
            custom_seed = 1;
        } else {
            // Jei argumentas nėra -rnd, tai yra failo pavadinimą
            strncpy(filename, argv[i], 255);
        }
    }

    // 2. Jei failas ne nurodytas
    if (strlen(filename) == 0) {
        strncpy(filename, argv[0], 255);
        int len = strlen(filename);
        if (len > 4) { // .exe keičiame į .cfg
            filename[len-1] = 'g';
            filename[len-2] = 'f';
            filename[len-3] = 'c';
            filename[len-4] = '.';
        }
    }
    printf("Inicijuojama reikšmė (seed): %d\n", seed);

    SimulationParams params;
    readParamsFromFile(filename, &params);

    SimulationResult withVip = simulate(&params, 1, seed);

    SimulationResult withoutVip = simulate(&params, 0, seed);

    printf("Procesas 1 (su VIP): \n");
    printSimulationResult(&withVip);

    printf("Procesas 2 (be VIP): \n");
    printSimulationResult(&withoutVip);

    int cmp = compareADTs(withVip.total_profit, withoutVip.total_profit);
    if (cmp < 0) {
        printf("Išvada: VIP sutartys yra pelningesnės.\n");
    } else if (cmp > 0) {
        printf("Išvada: VIP sutartys nuostolingos.\n");
    } else {
        printf("Išvada: Pelno skirtumo nėra.\n");
    }

    Done(&withVip.base_salary);
    Done(&withVip.overtime_salary);
    Done(&withVip.bonus_income);
    Done(&withVip.total_profit);

    Done(&withoutVip.base_salary);
    Done(&withoutVip.overtime_salary);
    Done(&withoutVip.bonus_income);
    Done(&withoutVip.total_profit);

    return 0;
}