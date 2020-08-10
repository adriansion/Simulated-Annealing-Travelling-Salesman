#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "readfile.h"

// Finds the distance of the straight line drawn between two specified nodes.
double findDistance(node *nodeA, node *nodeB) {
    int xComponent = abs(nodeA->xCoordinate - nodeB->xCoordinate);
    int yComponent = abs(nodeA->yCoordinate - nodeB->yCoordinate);

    return sqrt(pow(xComponent, 2) + pow(yComponent, 2));

}

// Calculates the cumulative distance of all the distances between specified matrix's nodes.
double mapDistances(nodeData *data) {
    double distance = 0;
    int *matrix = generateMatrix(data->nodeCount);

    for (int i = 0; i < data->nodeCount; i++) {
        for (int j = 0; j < data->nodeCount; j++) {
            if (matrix[(data->nodeCount * i) + j] != 0) {
                distance += findDistance(&data->nodes[i], &data->nodes[j]);
            }
        }
    }
    free(data->nodes);
    free(data);
    return distance;
}


