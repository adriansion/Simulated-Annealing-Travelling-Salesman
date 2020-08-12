#ifndef SIMULATED_ANNEALING_READFILE_H
#define SIMULATED_ANNEALING_READFILE_H

typedef struct {
    int xCoordinate;
    int yCoordinate;
} file_node;

typedef struct {
    int file_node_count;
    file_node *file_nodes;
} file_node_data;

file_node_data *readfile(char filename[]);

#endif //SIMULATED_ANNEALING_READFILE_H
