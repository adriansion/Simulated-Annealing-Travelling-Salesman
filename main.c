#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "readfile.h"

void printMatrixContents(int, const int *);

int main() {

//    // Seeding random function.
//    srand(time(NULL));
//
//    // Running matrix generator.
//    int nodeCount = 5;
//    int *matrix = generateMatrix(nodeCount);
//    printMatrixContents(nodeCount, matrix);
//    free(matrix);

    nodeData *data = readfile("nodeConfig.txt");

    for (int i = 0; i < data->nodeCount; i++) {
        printf("%d %d\n", data->nodes[i].xCoordinate, data->nodes[i].yCoordinate);
    }

    free(data->nodes);
    free(data);
    return 0;
}

// Prints matrix contents to standard output.
void printMatrixContents(int nodeCount, const int *matrix) {
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            printf("%d ", *(matrix + ((i * nodeCount) + j)));
        }
        printf("\n");
    }
}