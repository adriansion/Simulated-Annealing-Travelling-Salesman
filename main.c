#include <stdio.h>
#include "simulated-annealing.h"
#include <stdlib.h>

int main() {

    char filename[] = "nodeConfig.txt";
    const int iterations = 10000;

    state_matrix *pair = optimize(filename, iterations);

    if (pair != NULL) {
        printf("Found best state %.2f in %d iterations.\n", pair->state, iterations);
        free(pair->matrix);
        free(pair);
    }

    return 0;
}