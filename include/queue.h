#ifndef PRACTIS_QUEUE_H
#define PRACTIS_QUEUE_H
#include <stdlib.h>
#include "../include/bfs.h"

typedef struct{
    int front, rear, size;
    unsigned capacity;
    pos * array;
}Queue;

int enqueue(Queue * queue, pos item);
pos dequeue(Queue * queue);
pos front(Queue * queue);
Queue * create_queue(unsigned capacity);

#endif // PRACTIS_QUEUE_H