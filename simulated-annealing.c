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

             // First iteration.
            if (current_pair == NULL) current_pair = new_pair;

            // New pair's state is better than that of current pair.
            else if (current_pair->state > new_pair->state) {

                // Best pair and current pair point to the same matrix-state pair.
                if (best_pair == current_pair) {
                    best_pair = new_pair;
                }

                free(current_pair->matrix); free(current_pair);

                current_pair = new_pair;
            }

            // New pair's state is equal to or worse than that of current pair.
            else {

                // Generating stochastic probability to use new pair anyway.
                double jumpProbability = exp(((new_pair->state - current_pair->state) * -1) / temperature);

                // Probability accepted.
                if ((rand() % 1000) <= (int) (1000 * jumpProbability) - 1) {

                    // Current pair can be disregarded in exchange for new pair.
                    if (best_pair != current_pair) {
                        free(current_pair->matrix);
                        free(current_pair);
                    }

                    current_pair = new_pair;
                }

                // Probability denied. New pair can be disregarded.
                else {
                    free(new_pair->matrix);
                    free(new_pair);
                }
            }

            // First iteration.
            if (best_pair == NULL) best_pair = current_pair;

            // Current pair's state is better than that of best pair.
            else if (best_pair->state > current_pair->state) {

                // Disregard best pair.
                free(best_pair->matrix);
                free(best_pair);

                best_pair = current_pair;
            }
        }

        // Update temperature according to cooling schedule.
        temperature = decreaseTemperature(temperature);
    }

    // Node data is no longer needed.
    free(data->file_nodes); free(data);

    // Best pair and current pair do not point to the same state-matrix pair.
    if (best_pair != current_pair && current_pair != NULL) {

        // Disregard current pair.
        free(current_pair->matrix);
        free(current_pair);
    }

    return best_pair;
}

// Decreases global temperature according to linear cooling schedule; could use a geometric schedule.
double decreaseTemperature(double t) {
    return --t;
}