#pragma once

#include <stdbool.h>

#include "node.h"
 
typedef struct queue {
  int size;
  node *front;
  node *rear;
} queue;

typedef struct {
  node *head;
} stack;

