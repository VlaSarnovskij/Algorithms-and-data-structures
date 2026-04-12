#include <string.h>
#include <stdlib.h>
#include "priorityQueue.h" // 1lugu2023
#include "BigInteger.h" // 1masi2289

typedef struct{
    int days;        
    int A;          // Franšiza
    int A1;         // Bonus už VIP
    int U;          // Valandinis atlyginimas
    int K;          // Meistrų skaičius
    int T1;         // Tikimybė, kad atvyks VIP klientas
    int T2;         // Tikimybė, kad atvyks įprastas klientas
} SimulationParams;

typedef struct {
    int vip_count;          // Kiek VIP aptarnauta
    int regular_count;      // Kiek įprastų aptarnauta
    long base_salary;       // Išlaidos pagrindiniam atlyginimui
    long overtime_salary;   // Išlaidos viršvalandžiams
    long bonus_income;      // Pajamos iš premijų (A1)
    long total_profit;      // Galutinis pelnas
} SimulationResult;

void readParamsFromFile(const char* filename, SimulationParams* params);

int hasVipTask(priorityQueue *pq, int masters_busy[], int masters_work_type[], int K);

SimulationResult simulate(const SimulationParams* params, int hasContracts, int seed);

void printSimulationResult(const SimulationResult *result);