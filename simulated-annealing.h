#ifndef SIMULATED_ANNEALING_SIMULATED_ANNEALING_H
#define SIMULATED_ANNEALING_SIMULATED_ANNEALING_H

#include "readfile.h"
#include "distances.h"

int *optimize(char filename[], int);

void decreaseTemperature(void);

#endif
