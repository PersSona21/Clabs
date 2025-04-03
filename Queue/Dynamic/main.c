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

void test_multiple_push_pop() {
    Queue q;
    create(&q);
    for (int i = 0; i < 5; i++) {
        assert(push(&q, i));
    }
    for (int i = 0; i < 5; i++) {
        assert(top(&q) == i);
        assert(pop(&q));
    }
    assert(empty(&q));
    printf("test_multiple_push_pop passed!\n");
}

void test_destroy() {
    Queue q;
    create(&q);
    push(&q, 1);
    push(&q, 2);
    destroy(&q);
    assert(empty(&q));
    printf("test_destroy passed!\n");
}

int main() {
    test_create();
    test_push();
    test_pop();
    test_top();
    test_multiple_push_pop();
    test_destroy();
    printf("All tests passed!\n");
    return 0;
}
