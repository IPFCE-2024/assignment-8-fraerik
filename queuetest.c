#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

int main() {
    queue q;
    int x0 = 5, x1 = 10;
    int y0, y1;

// Test 1, when initialize is executed queue should be empty or else it wont run
    initialize(&q);
    assert(empty(&q) == true); // Asserts queue should be empty

// Test 2, when executed q should be the same as before executed, hence the x = y
    enqueue(&q, x0); // First element enqueued
    y0 = dequeue(&q); // y0 set to be value of dequeue or x0
    assert(empty(&q) == true); // Same as test 1
    assert(x0 == y0); // x must be the same as y

// Test 3, like Test 2. Though here we have, x0 = y0 AND x1 = y1 
    enqueue(&q, x0); // First element enqueued
    enqueue(&q, x1); // Second element enqueued
    y0 = dequeue(&q); // y0 set to be value of first dequeue or x0
    y1 = dequeue(&q); // y1 set to be value of second dequeue or x1

// After this queue goes back to being empty, how it started, or its original state
    assert(empty(&q) == true); 
    assert(x0 == y0); 
    assert (x1 == y1);

    printf("Test have passed, lawful abiding citizen\n"); // Congratulation prompt for passing all tests

    return 0;
}