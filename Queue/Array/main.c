#include <stdio.h>
#include <assert.h>
#include "Queue.h"


void test_create() {
    Queue q;
    create(&q);
    assert(empty(&q));
    assert(size(&q) == 0);
    printf("test_create passed!\n");
}

void test_push() {
    Queue q;
    create(&q);
    assert(push(&q, 10));
    assert(!empty(&q));
    assert(size(&q) == 1);
    assert(top(&q) == 10);
    printf("test_push passed!\n");
}

void test_pop() {
    Queue q;
    create(&q);
    push(&q, 10);
    push(&q, 20);
    assert(pop(&q));
    assert(size(&q) == 1);
    assert(top(&q) == 20);
    assert(pop(&q));
    assert(empty(&q));
    assert(!pop(&q));
    printf("test_pop passed!\n");
}

void test_top() {
    Queue q;
    create(&q);
    push(&q, 42);
    assert(top(&q) == 42);
    push(&q, 84);
    assert(top(&q) == 42);
    printf("test_top passed!\n");
}

void test_overflow() {
    Queue q;
    create(&q);
    for (int i = 0; i < POOL_SIZE; i++) {
        assert(push(&q, i));
    }
    assert(!push(&q, 100)); // Должен быть переполнен
    printf("test_overflow passed!\n");
}

int main() {
    test_create();
    test_push();
    test_pop();
    test_top();
    test_overflow();
    printf("All tests passed!\n");
    return 0;
}
