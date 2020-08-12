#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Retrieves valid adjacency matrix from attemptGeneration, which sometimes returns NULL.
int *generateMatrix(int nodeCount) {

    int *matrix = attemptGeneration(nodeCount);

    while (matrix == NULL) {

        matrix = attemptGeneration(nodeCount);

    }

    return matrix;

}


// Attempts to create a valid adjacency matrix; will return NULL if too many queue recycles occur.
int *attemptGeneration(int nodeCount) {

    int *matrix = (int *) malloc(nodeCount * nodeCount * sizeof(int));

    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {

            matrix[(nodeCount * i) + j] = 0;

        }
    }


    // Initializing spotQueue.
    int unfilledRows = nodeCount, selectedRow;
    int queueContents[nodeCount];
    Queue spotQueue = queue_ini(nodeCount);


    // Populating spotQueue.
    for (int i = 0; i < nodeCount; i++) {

        queueContents[i] = i;

    }


    for (int i = 0; i < nodeCount; i++) {

        selectedRow = rand() % unfilledRows;

        queue_add(spotQueue, queueContents[selectedRow]);

        // Replacing array value to simulate array shrinkage.
        queueContents[selectedRow] = queueContents[unfilledRows - 1];
        unfilledRows--;

    }


    // Iterating through matrix columns and applying their row values.
    int recycles;

    for (int i = 0; i < nodeCount; i++) {

        recycles = 0;

        // Recycling value if necessary.
        while (queue_peek(spotQueue) == i || matrix[(nodeCount * queue_peek(spotQueue)) + i] != 0) {

            recycles++;

            if (recycles >= spotQueue->size) {

                queue_free(spotQueue);
                free(matrix);
                return NULL;

            } else {

                queue_add(spotQueue, queue_poll(spotQueue));

            }
        }

        // Setting edge in adjacency matrix.
        matrix[(nodeCount * i) + queue_poll(spotQueue)] = 1;

    }

    queue_free(spotQueue);
    return matrix;

}