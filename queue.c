#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Opgave 3
typedef struct node {  // Node struct for the lists
    int data;
    struct node* next;
} node;

typedef struct { // Queue struct
    node* front;
    node* rear;
    int count;
} queue;

void initialize(queue *q) { // Starts or initizlizes queue
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}


bool empty(const queue *q) { // Checks if queue is empty
    return q->count == 0;
}

bool full(const queue *q) { // Checks if queue is full
    return false;
}
  

void enqueue(queue *q, int x) { // Adds element at the end of queue, for last
    node* new = (node*)malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    if (q->rear == NULL) {
        q->front = new; // If queue is empty first and last becomes the same
        q->rear = new;
    } else {
        q->rear->next = new; // Else new node is updated to the last as new
        q->rear = new;
    }
    q->count++; // count++ because we add an element
}

int dequeue(queue *q) { // Removes the first element in queue
    if (empty(q)) {
        printf("Queue is empty\n");
        exit(1); // If queue is empty, close program
    }

    int x = q->front->data; // First nodes data gets stored in x
    node* temp = q->front; // Saves a temporary pointer "q->first", temporary because this is the one to be removed
    q->front = q->front->next; // Moves first node to next node, here it is practically already removed from the list
    free(temp); // Removes the memory of the temporary pointer

    if (q->front == NULL) { // If queue is empty after removal we update to NULL
        q->rear = NULL;
    }

    q->count--; // count-- because we remove an element
    return x; // we return x, because the temporary pointer is stored there, the one we want to remove
}

// Opgave 4

typedef struct node { // Same struct as in opgave 3
    int data;
    struct node* next;
} node;

typedef struct queue2 { // Here we define our nonstacks a node pointers
    node* notastack1;
    node* notastack2;
} queue2;

void initializeQueue(queue2 *q) { // Function to start a queue by setting our values to NULL
    q->notastack1 = NULL;
    q->notastack2 = NULL;
}

void push(int element, node **head) { // Function that pushes an element on our stack
    node* new = (node*)malloc(sizeof(node));
    if (!new) {
        printf("Malloc problems, exiting...\n"); // If there are memory problems with the malloc function the program should exit
        exit(1);
    }
    new->data = element; // The pused node becomes the integer i.e. the element
    new->next = *head; // New node becomes the pointer to head
    *head = new; // The pointer points to the new element we have pushed
}

int pop(node **head) { // Function that pops an element from the stack
    if (*head == NULL) {
        printf("Stack problems, exiting...\n"); // If there are problems with the stack the program should exit
        exit(1);
    }
    int result = (*head)->data; // The popped element gets stored as result
    node* temp = *head; // A temporary node is set as the pointer for head
    free(temp); // The temp node is removed
    return result;
}

void enqueueStack(queue2 *q, int x) { // Function to enqueue a stack
    push(x, &q->notastack1); // Pushes pointer to notastack1 
}

int dequeueStack(queue2 *q) { // Function to dequeue a stack
    if (q->notastack2 == NULL && q->notastack1 == NULL) {
        printf("There is something wrong with the nonstacks\n"); // Error code if both values are NULL
        exit(1);
    }

    if (q->notastack2 == NULL) {
        while (q->notastack1 != NULL) { // If notastack 2 is NULL but notastack1 isnt we pop notastack1 and push notastack2
            int element = pop(&q->notastack1);
            push(element, &q->notastack2);
        }
    }
    return pop(&q->notastack2); // We get returned the popped value 
}

int Check_If_Empty(const queue2 *q) { // Function to check if queue is empty
    return q->notastack1 == NULL && q->notastack2 == NULL;
}