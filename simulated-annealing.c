#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "simulated-annealing.h"

state_matrix *optimize(char *filename, int iterations) {

    // Seeding random function.
    srand(time(NULL));

    // Retrieving 2D coordinate data from specified filename.
    file_node_data *data         = readfile(filename);
    if (data == NULL) return       NULL;

    state_matrix *new_pair       = NULL;
    state_matrix *current_pair   = NULL;
    state_matrix *best_pair      = NULL;

    const double temp_MAX        = 500;
    double temperature           = temp_MAX;


    while (temperature > 0) {
        for (int i = 0; i < iterations / temp_MAX; i++) {

            new_pair = mapDistances(data);

            if (current_pair == NULL) {
                current_pair = new_pair;

            } else if (current_pair->state > new_pair->state) {

                if (best_pair != current_pair) {

                    free(current_pair->matrix);
                    free(current_pair);

                } else {

                    free(best_pair->matrix);
                    free(best_pair);

                    best_pair = new_pair;
                }
                current_pair = new_pair;

            } else {

                // Generating stochastic probability to enter higher state.
                double jumpProbability = exp(((new_pair->state - current_pair->state) * -1) / temperature);

                if ((rand() % 1000) <= (int) (1000 * jumpProbability) - 1) {

                    if (best_pair != current_pair) {

                        free(current_pair->matrix);
                        free(current_pair);

                    }
                    current_pair = new_pair;

                } else {

                    free(new_pair->matrix);
                    free(new_pair);

                }
            }
            if (best_pair == NULL) {
                best_pair = current_pair;

            } else if (best_pair->state > current_pair->state) {

                free(best_pair->matrix);
                free(best_pair);

                best_pair = current_pair;
            }
        }
        temperature = decreaseTemperature(temperature);
    }

    free(data->file_nodes);
    free(data);

    if (best_pair != current_pair && current_pair != NULL) {

        free(current_pair->matrix);
        free(current_pair);

    }

    return best_pair;
}

// Decreases global temperature according to linear cooling schedule; could use a geometric schedule.
double decreaseTemperature(double t) {
    return --t;
}