#include "../include/queue.h"

Queue * create_queue(unsigned capacity){

    Queue * queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->array = (pos*)malloc(queue->capacity * sizeof(pos));
    return queue;

}

int is_full(Queue *queue){
    return (queue->size == queue->capacity);
}

int is_empty(Queue *queue){
    return (queue->size == 0);
}

int enqueue(Queue * queue, pos item){
    if (is_full(queue))
        return 0;
    if (queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->size++;
    queue->array[queue->rear] = item;
    return 1;
}

pos dequeue(Queue *queue){
    pos t;
    if (is_empty(queue)){
        t.x = -2;
        t.y = -2;
        return t;
    }
    t = queue->array[queue->front];
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

pos front(Queue * queue){
    pos t;
    if (is_empty(queue)){
        t.x = -2;
        t.y = -2;
        return t;
    }
    return queue->array[queue->front];
 
}
 