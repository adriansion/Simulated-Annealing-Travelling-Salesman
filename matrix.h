#ifndef SIMULATED_ANNEALING_MATRIX_H
#define SIMULATED_ANNEALING_MATRIX_H

#include "queue.h"
#include "readfile.h"

typedef struct {
    double state;
    int *matrix;
} state_matrix;

double findDistance(file_node *nodeA, file_node *nodeB);

state_matrix *mapDistances(file_node_data *data);

int *generateMatrix(int);

int *attemptGeneration(int);

void printMatrixContents(int, const int *);

#endif
