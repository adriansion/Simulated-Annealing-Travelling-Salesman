// In-built implementation of the Queue data structure.
// Peek and Poll return -1 when empty.

#include <stdlib.h>
#include "queue.h"

// Dynamically allocates memory for Queue.
Queue queue_ini(int capacity) {
    Queue queue;
    queue = (Queue) malloc(sizeof(queue_struct));
    queue->nodes = (node) malloc((capacity) * sizeof(int));
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

// Clears dynamic memory allocated to Queue.
void queue_free(Queue queue) {
    free(queue->nodes);
    free(queue);
}

// Inserts specified value to tail of Queue.
void queue_add(Queue queue, int value) {
    if (queue->capacity == queue->size) { // Queue is full.
        return;
    } else {
        queue->nodes[queue->size] = value;
        queue->size++;
    }
}

// Returns value of Queue's top node.
int queue_peek(Queue queue) {
    if (queue->size == 0) { // Queue is empty.
        return -1;
    } else {
        return queue->nodes[0];
    }
}

// Returns value of Queue's top node while removing that node from the Queue.
int queue_poll(Queue queue) {
    if (queue->size == 0) { // Queue is empty.
        return -1;
    } else {
        int retValue = queue->nodes[0];
        for (int i = 0; i < queue->size - 1; i++) {
            queue->nodes[i] = queue->nodes[i + 1];
        }
        queue->size--;
        return retValue;
    }
}