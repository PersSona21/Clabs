#ifndef QUEUE_H_
#define QUEUE_H_

typedef int T;

struct Queue_;
typedef struct Queue_ Queue;

struct Item_;
typedef struct Item_ Item;

void create(Queue *);
void clean(Queue *);
void push(Queue *, T);
void pop(Queue *);
T * front(Queue *);


#endif