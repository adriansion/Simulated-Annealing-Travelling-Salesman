#include <stdlib.h>
#include <math.h>
#include "distances.h"

// Finds the distance of the straight line drawn between two specified nodes.
double findDistance(file_node *nodeA, file_node *nodeB) {

    int xComponent = abs(nodeA->xCoordinate - nodeB->xCoordinate);
    int yComponent = abs(nodeA->yCoordinate - nodeB->yCoordinate);

    return sqrt(pow(xComponent, 2) + pow(yComponent, 2));

}


// Calculates the cumulative distance between all of specified matrix's nodes.
double mapDistances(file_node_data *data) {

    double distance = 0;
    int *matrix = generateMatrix(data->file_node_count);

    for (int i = 0; i < data->file_node_count; i++) {
        for (int j = 0; j < data->file_node_count; j++) {

            if (matrix[(data->file_node_count * i) + j] != 0) {

                distance += findDistance(&data->file_nodes[i], &data->file_nodes[j]);

            }
        }
    }


    free(matrix);
    return distance;

}
