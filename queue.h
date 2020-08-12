#ifndef SIMULATED_ANNEALING_QUEUE_H
#define SIMULATED_ANNEALING_QUEUE_H

typedef struct {
    int size, capacity;
    int *queue_nodes;
} queue_struct;

typedef queue_struct *Queue;

Queue queue_ini(int capacity);

void queue_free(Queue);

void queue_add(Queue, int value);

int queue_peek(Queue);

int queue_poll(Queue);


#endif
