#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdbool.h>

typedef int T;


typedef struct Item{
    T data;
    struct Item* next;
} Item;

typedef struct{
    Item* first;
    Item* last;
    size_t size;
} Queue;

void create(Queue* q){
    q->first = q->last = (Item*) malloc(sizeof(Item));
    q->size = 0;
}

bool empty(Queue* q){
    return q->first == q->last; // or q->size == 0
}

size_t size(Queue* q){
    return q->size;
}

T top(Queue* q){
    if (q->last != q->first)
        return q->first->data;
    return -1;
}

bool push(Queue* q, T t){
    if (!(q->last->next = (Item *) malloc(sizeof(Item))))
        return false;
    q->last->data = t;
    q->last = q->last->next;
    q->size++;
    return true;
}

bool pop(Queue* q){
    if (q->first == q->last)
        return false;
    Item* ptr = q->first;
    q->first = q->first->next;
    q->size--;
    free(ptr);
    return true;
}

void destroy(Queue* q){
    while (!empty(q)){
        Item* ptr = q->first;
        q->first = q->first->next;
        free(ptr);
    }
    // free(q->first); // смысл этой строки мне не понятен
    q->first = q->last = 0;
    q->size = 0;
}

// void destroy(Queue* q){
//     Item* ptr = q->first;
//     q->first = q->first->next;
//     free(ptr);
//     if(q->first)
//         destroy(q);
//     q->last = 0;
//     q->first = 0;
//     q->size = 0;
// }

#endif