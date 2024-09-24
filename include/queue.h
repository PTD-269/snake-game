#ifndef QUEUE_H
#define QUEUE_H

#include "position.h"

typedef struct Node {
    Position data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    void (*init)(struct Queue*);
    int (*isEmpty)(struct Queue*);
    void (*enqueue)(struct Queue*, Position);
    Position (*dequeue)(struct Queue*);
    void (*free)(struct Queue*);
} Queue;

Queue* createQueue();

#endif // QUEUE_H