#ifndef PRACTIS_QUEUE_H
#define PRACTIS_QUEUE_H
#include <stdlib.h>

typedef struct{
    int front, rear, size;
    unsigned capacity;
    int * array;
}Queue;

int enqueue(Queue * queue, int item);
int dequeue(Queue * queue);
Queue * create_queue(unsigned capacity);

#endif // PRACTIS_QUEUE_H