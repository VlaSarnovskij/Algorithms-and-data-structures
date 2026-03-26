#include <stdio.h>

int main() {
    int N, M, S;
    scanf("%d %d %d", &N, &M, &S);

    int *numbers = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        &numbers[i] = i + 1; // Initialize the array with numbers from 1 to N
    }

    int 

    for (int i = 0; i < M; i++){

    }

    free(numbers); // Free the allocated memory
    return 0;
}