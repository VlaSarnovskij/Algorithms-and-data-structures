#include "simulation.h"
#include <stdio.h>

void readParamsFromFile(const char* filename, SimulationParams* params){
    FILE* file = fopen(filename, "r");

    int* fields[] = {
        &params->days, &params->A, &params->A1, 
        &params->U, &params->K, &params->T1, 
        &params->T2
    };

    char line[256];

    for (int i = 0; i < 7; ++i) {
        if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d", fields[i]);
        }
    }

    fclose(file);
}

void addIntToBI(BigInteger** dest, int value) {
    char buf[64];
    sprintf(buf, "%d", value);
    
    BigInteger* valBI = Create();
    stringToBigInteger(buf, valBI);
    
    BigInteger* temp = BigIntegerAdd(*dest, valBI);
    
    Done(dest);      
    *dest = temp;    
    
    Done(&valBI);    
}

int hasVipTask(priorityQueue *pq, int masters_busy[], int masters_work_type[], int K) {
    // Patikriname, ar eilėje yra VIP užduotis
    if (!pq_IsEmpty(pq) && pq_Peek(pq) == 1) {
        return 1;
    }
    // Patikriname, ar kuris nors meistras dirba su VIP užduotimi
    for (int i = 0; i < K; i++) {
        if (masters_busy[i] > 0 && masters_work_type[i] == 1) {
            return 1;
        }
    }
    return 0;
}

SimulationResult simulate(const SimulationParams* params, int hasContracts, int seed){
    // Inicializacija
    SimulationResult result; 
    result.bonus_income = Create();
    stringToBigInteger("0", result.bonus_income);
    
    result.base_salary = Create();
    stringToBigInteger("0", result.base_salary);
    
    result.overtime_salary = Create();
    stringToBigInteger("0", result.overtime_salary);

    result.vip_count = 0;
    result.regular_count = 0;

    priorityQueue *pq = pq_Create(1);
    srand(seed);

    // Pagrindinis ciklas
    int masters_busy[params->K]; // 0 - laisvas, >0 - užimtas iki šio laiko
    int masters_work_type[params->K]; // 1 - VIP, 0 - įprastas
    for (int i = 0; i < params->K; i++) {
        masters_busy[i] = 0;
        masters_work_type[i] = 0;
    }

    int days = params->days;
    while (days > 0) {
        int hour = 0;

        while (hour < 8 || (hasVipTask(pq, masters_busy, masters_work_type, params->K) && hour < 24)) { 
            
            // Kliento atvykimas
            if (hour < 8) {
                    int randomValue = rand() % 101; // 0-100 
                    if (randomValue < params->T1 && hasContracts) {
                        // Atvyko VIP klientas 1
                        pq_Insert(pq, 1, 1);
                    } else if (randomValue < (params->T1 + params->T2)) {
                        // Atvyko įprastas klientas 0
                        pq_Insert(pq, 0, 0);
                    }
            }

            // Darbo pasiskirstymas
            for (int i = 0; i < params->K; ++i) {
                if (masters_busy[i] == 0 && !pq_IsEmpty(pq)) {
                    int next_car_vip = (pq_Peek(pq) == 1);
                    
                    if (hour < 8 || next_car_vip) {
                        int type = pq_Remove(pq);
                        int TR = 1 + rand() % ((5 * params->K) - 1 + 1); // Remonto trukmė [1; 5*K] valandų
                        
                        masters_busy[i] = TR;
                        masters_work_type[i] = type;

                        if (type == 1) { 
                            result.vip_count++; 
                            addIntToBI(&result.bonus_income, params->A1);
                        } else { 
                            result.regular_count++; 
                        }
                    }
                }

                // Darbas
                if (masters_busy[i] > 0) {
                    if (hour < 8 || masters_work_type[i] == 1) {
                        char str[256];        

                        if (hour >= 8) {
                            addIntToBI(&result.overtime_salary, params->U * 2); // Viršvalandinis atlyginimas
                        } else {
                            addIntToBI(&result.base_salary, params->U); // Pagrindinis atlyginimas
                        }

                        --masters_busy[i];
                    }
                }
            }
            ++hour;

            if (hour > 24) break;
        }
        --days;
    }

    result.total_profit = BigIntegerSub(result.bonus_income, result.overtime_salary);    
    pq_Destroy(pq);

    return result;
}

void printSimulationResult(const SimulationResult *result) {
    char* bonusStr = toString(result->bonus_income);
    char* baseStr = toString(result->base_salary);
    char* overStr = toString(result->overtime_salary);
    char* profitStr = toString(result->total_profit);

    printf("----------------------------------------------\n");
    printf("Aptarnautų automobilių: %d ", result->vip_count + result->regular_count);
    printf("(iš jų VIP: %d, ", result->vip_count);
    printf("įprastų: %d)\n", result->regular_count);
    printf("Pajamos iš premijų (A1): %s\n", bonusStr);
    printf("Išlaidos pagrindiniam atlyginimui: %s\n", baseStr);
    printf("Išlaidos viršvalandžiams (x2): %s\n", overStr);
    printf("----------------------------------------------\n");
    printf("Galutinis pelnas: %s\n\n", profitStr);

    free(profitStr);
    free(bonusStr);
    free(baseStr);
    free(overStr);
}