#include "Queue.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>



struct Item_ {
    T data;
    struct Item_ * prev;
};

struct Queue_ {
    Item * first;
    Item * last;
    size_t size;
};

void create(Queue * q){
    q->size = 0;
    Item * terminator = malloc(sizeof(Item));
    q->first = terminator;
    q->last = terminator;
};

void clean(Queue * q){
    while(q->first != q->last){
        Item * current = q->first;
        q->first = q->first->prev;
        free(current);
    }
};


void push(Queue * q, T t){
    Item * newTerminator = malloc(sizeof(Item));
    q->last->data = t;
    q->last->prev = newTerminator;
    q->last = newTerminator;
    ++q->size;
};


void pop(Queue * q){
    if (q->first == q->last) return;
    Item * first = q->first;
    q->first = q->first->prev;
    free(first);
    --q->size;
}

T * front(Queue * q){
    if (q->first != q->last){
        return &q->first->data;
    }
    return 0;
};