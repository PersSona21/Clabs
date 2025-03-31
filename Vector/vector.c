#include <stdlib.h>
#include "Vector.h"


void create(Vector *v, int size){
    v->size = size;
    v->data = malloc(sizeof(T) * v->size);
}

bool empty(Vector *v){
    return v->size == 0;
}

int size(Vector *v){
    return v->size;
}

T load(Vector *v, int i){
    if ((i >= 0) && (i < v->size))
        return v->data[i];
    return -1;
}

void save(Vector *v, int i, T t){
    if ((i >= 0) && (i < v->size))
        v->data[i] = t;
}

void resize(Vector *v, int size){
    v->size = size;
    v->data = realloc(v->data, sizeof(T) * v->size);
}

bool equal(Vector *l, Vector *r){
    if (l->size != r->size)
        return false;
    for (int i = 0; i < l->size; ++i)
        if (l->data[i] != r->data[i])
            return false;
    return true;
}


void destroy(Vector *v){
    v->size = 0;
    free(v->data);
}
