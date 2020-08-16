#ifndef SIMULATED_ANNEALING_SIMULATED_ANNEALING_H
#define SIMULATED_ANNEALING_SIMULATED_ANNEALING_H

#include "readfile.h"
#include "matrix.h"

state_matrix *optimize(char *filename, int iterations);

double decreaseTemperature(double);

#endif
