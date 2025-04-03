#include "./Queue.h"
#include <stdbool.h>


void create(Queue *q){
    q->first = 0;
    q->size = 0;
}

bool empty(Queue *q){
    return q->size == 0;
}

size_t size(Queue *q){
    return q->size;
}

bool push(Queue *q, T t){
    if (q->size == POOL_SIZE)
        return false;
    q->data[(q->first + q->size) % POOL_SIZE] = t;
    q->size++;
    return true;
}

bool pop(Queue *q){
    if (!q->size)
        return false;
    q->first++;
    q->first %= POOL_SIZE;
    q->size--;
    return true;
}

T top(Queue *q){
    if (q->size)
        return q->data[q->first];
    return -1;
}

void destroy(Queue *q){
    q->size = 0; // в целом не обязательно
}