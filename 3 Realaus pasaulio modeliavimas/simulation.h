#include <string.h>
#include <stdlib.h>
#include "priorityQueue.h" // 1lugu2023
#include "BigInteger.h" // 1masi2289

typedef struct{
    int A;          // Франшиза
    int A1;         // Бонус за VIP
    int U;        // Зарплата в час
    int K;          // Число мастеров
    int T1;         // Вероятность появления VIP
    int T2;         // Вероятность обычного клиента
} SimulationParams;

typedef struct {
    long total_profit;      // Итоговая прибыль
    int vip_count;          // Сколько VIP обслужено
    int regular_count;      // Сколько обычных обслужено
    double overtime_hours;  // Сколько часов мастера работали сверхурочно
    long bonus_income;      // Доход только от бонусов A1
} SimulationResult;

void readParamsFromFile(const char* filename, SimulationParams* params);

SimulationResult simulate(SimulationParams params, int days, int hasContracts);
