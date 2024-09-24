#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "position.h"

static void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

static int isEmpty(Queue* q) {
    return q->front == NULL;
}

static void enqueue(Queue* q, Position pos) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = pos;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

static Position dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        Position empty = { -1, -1 };
        return empty;
    }
    Node* temp = q->front;
    Position pos = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return pos;
}

static void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->init = initQueue;
    q->isEmpty = isEmpty;
    q->enqueue = enqueue;
    q->dequeue = dequeue;
    q->free = freeQueue;
    q->init(q);
    return q;
}