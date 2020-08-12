#include <stdio.h>
#include "simulated-annealing.h"

int main() {

    char filename[] = "nodeConfig.txt";
    const int iterations = 10;

    optimize(filename, iterations);

//    printf("%f\n", mapDistances(readfile(filename)));

    return 0;
}