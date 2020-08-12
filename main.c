#include <stdio.h>
#include "simulated-annealing.h"

int main() {

    char filename[] = "nodeConfig.txt";
    const int iterations = 5000;

    double state = optimize(filename, iterations);

    if (state != -1) {
        printf("Found best state %.2f in %d iterations.\n", state, iterations);
    }

    return 0;
}