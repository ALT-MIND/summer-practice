#include "../include/queue.h"

Queue * create_queue(unsigned capacity){

    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;

}

int is_full(Queue *queue){
    return (queue->size == queue->capacity);
}

int is_empty(Queue *queue){
    return (queue->size == 0);
}

int enqueue(Queue * queue, int item){
    if (is_full(queue))
        return -1;
    if (queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->size++;
    queue->array[queue->rear] = item;
    return 1;
}

int dequeue(Queue *queue){
    if (is_empty(queue))
        return -1;
    int t = queue->array[queue->front];
    if (queue->front + 1 > queue->rear){
        queue->front = queue->rear = -1;
        queue->size = 0;
    }
    else{
        queue->front++;
        queue->size--;
    }
    return t;
}
 