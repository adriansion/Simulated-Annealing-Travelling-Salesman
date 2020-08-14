#include <stdio.h>
#include "simulated-annealing.h"
#include <stdlib.h>

int main() {

    char filename[] = "nodeConfig.txt";
    const int iterations = 1;

    double state = optimize(filename, iterations);

    if (state != -1) {
        printf("Found best state %.2f in %d iterations.\n", state, iterations);
    }

//    file_node_data *data = readfile(filename);
//    state_matrix pair = mapDistances(data);
//
//
//    free(data->file_nodes);
//    free(data);
//
//    free(pair->matrix);
//    free(pair);

    return 0;
}