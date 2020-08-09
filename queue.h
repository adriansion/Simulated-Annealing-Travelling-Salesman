#ifndef SIMULATED_ANNEALING_QUEUE_H
#define SIMULATED_ANNEALING_QUEUE_H

typedef int *node;

typedef struct {
    int size, capacity;
    node nodes;
} queue_struct;

typedef queue_struct *Queue;

Queue queue_ini(int capacity);

void queue_free(Queue);

void queue_add(Queue, int value);

int queue_peek(Queue);

int queue_poll(Queue);


#endif
