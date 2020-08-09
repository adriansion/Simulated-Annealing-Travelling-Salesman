#include <stdlib.h>
#include "queue.h"
#include "matrix.h"

// Retrieves valid adjacency matrix from attemptGeneration, which sometimes returns NULL.
int *generateMatrix(int nodeCount) {
    int *matrix = attemptGeneration(nodeCount);
    while (matrix == NULL) {
        free(matrix);
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

    // Initialize spotQueue
    int unfilledRows = nodeCount, selectedRow;
    int queueContents_PreRandom[nodeCount];

    Queue spotQueue = queue_ini(nodeCount);

    for (int i = 0; i < nodeCount; i++) {
        queueContents_PreRandom[i] = i;
    }

    for (int i = 0; i < nodeCount; i++) {
        selectedRow = rand() % unfilledRows;

        queue_add(spotQueue, queueContents_PreRandom[selectedRow]);

        // Replace array value to simulate array shrinkage
        queueContents_PreRandom[selectedRow] = queueContents_PreRandom[unfilledRows - 1];
        unfilledRows--;
    }


    // Iterate through matrix columns and apply row values
    int recycleCounter;

    for (int i = 0; i < nodeCount; i++) {
        recycleCounter = 0;

        // Recycling value if necessary
        while (queue_peek(spotQueue) == i || matrix[(nodeCount * queue_peek(spotQueue)) + i] != 0) {
            recycleCounter++;
            if (recycleCounter >= spotQueue->size) {
                queue_free(spotQueue);
                return NULL;
            } else {
                queue_add(spotQueue, queue_poll(spotQueue));
            }
        }
        // Setting edge in adjacency matrix
        matrix[(nodeCount * i) + queue_poll(spotQueue)] = 1;

    }
    queue_free(spotQueue);
    return matrix;
}