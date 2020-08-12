#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "simulated-annealing.h"

const double TEMPERATURE_MAX = 500;
double temperature = TEMPERATURE_MAX;

int *optimize(char filename[], int iterations) {
    // Seeding random function.
    srand(time(NULL));

    file_node_data *data = readfile(filename);
    if (data == NULL) {
        return NULL;
    } else {
        double currentState = -1, bestState = -1, newState;

        int *currentOptimum = NULL;

        while (temperature > 0) {

            for (int i = 0; i < iterations / TEMPERATURE_MAX; i++) {
                file_node_data *data = readfile(filename);

                newState = mapDistances(data);

                if (currentState > newState || currentState == -1) {
                    currentState = newState;
                } else {
                    double probabilityToEnterHigherState = exp(((newState - currentState) * -1) / temperature);
                    int higherStateSelection = (int) (1000 * probabilityToEnterHigherState) - 1;

                    if ((rand() % 1000) <= higherStateSelection) {
                        currentState = newState;
                    }
                }
                if (bestState > currentState || bestState == -1) {
                    bestState = currentState;
                }
            }
            decreaseTemperature();
        }
        free(data->file_nodes);
        free(data);
        printf("%f", bestState);
        return currentOptimum;
    }
}

void decreaseTemperature(void) {
    temperature--;
}