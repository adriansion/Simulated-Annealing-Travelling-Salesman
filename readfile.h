#ifndef SIMULATED_ANNEALING_READFILE_H
#define SIMULATED_ANNEALING_READFILE_H

typedef struct {
    int xCoordinate;
    int yCoordinate;
} node;

typedef struct {
    int nodeCount;
    node *nodes;
} nodeData;

nodeData *readfile(char filename[]);

#endif //SIMULATED_ANNEALING_READFILE_H
