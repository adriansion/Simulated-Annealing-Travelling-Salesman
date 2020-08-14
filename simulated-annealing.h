#ifndef SIMULATED_ANNEALING_SIMULATED_ANNEALING_H
#define SIMULATED_ANNEALING_SIMULATED_ANNEALING_H

#include "readfile.h"
#include "matrix.h"
//#include "distances.h"

double optimize(char *filename, int iterations);

void decreaseTemperature(void);

#endif
