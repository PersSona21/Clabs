#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct{
    T* data;
    int size;
} Vector;

void create(Vector* v, int size);
bool empty(Vector* v);
int size(Vector* v);
T load(Vector* v, int i);
void save(Vector* v, int i, T t);
void resize(Vector* v, int size);
bool equal(Vector* left, Vector* right);
void destroy(Vector* v);

#endif