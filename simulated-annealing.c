#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "simulated-annealing.h"

const double T_MAX = 500;
double temperature = T_MAX;

double optimize(char *filename, int iterations) {

    // Seeding random function.
    srand(time(NULL));

    // Retrieving 2D coordinate data from specified filename.
    file_node_data *data = readfile(filename);

    if (data != NULL) {

        int *currentOptimum = NULL;
        double currentState = -1;
        double bestState    = -1;
        double newState;


        while (temperature > 0) {

            for (int i = 0; i < (iterations / T_MAX); i++) {

                newState = mapDistances(data);

                if (currentState > newState || currentState == -1) {

                    currentState = newState;

                } else {

                    // Generating stochastic probability to enter higher state.
                    double higherStateProbability = exp(((newState - currentState) * -1) / temperature);

                    if ((rand() % 1000) <= (int) (1000 * higherStateProbability) - 1) {

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
        return bestState;

    }
    return -1;
}


// Decreases global temperature according to linear cooling schedule; could use a geometric schedule.
void decreaseTemperature(void) {

    temperature--;

}