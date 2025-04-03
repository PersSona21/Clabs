#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>

typedef int T;
#define POOL_SIZE 100

typedef struct{
    T data[POOL_SIZE];
    size_t first;
    size_t size;
} Queue;

void create(Queue* q);
bool empty(Queue* q);
size_t size(Queue* q);
T top(Queue* q);
bool push(Queue* q, T t);
bool pop(Queue* q);
void destroy(Queue* q);

#endif