#include "insertion_sort.h"

void isort(node* list) {
node* sorted = NULL; // When pointer is sorted = NULL

node* current = list; // Goes through the list
while (current != NULL) {
    node* next = current->next; // Saves next node

    if (sorted == NULL || current->data < sorted->data) { // Current gets put into sorted list
        current->next = sorted; // Gets puts in the beginning of the sorted list
        sorted = current; // Says list is currently sorted
    } else {
        node* temp = sorted; // Finds a temporary position to store current node
        while (temp->next != NULL && temp->next->data < current->data) {
            temp = temp->next; // The temporary node becomes the next node
        }
        // Current node gets put after the temporary node
        current->next = temp->next;
        temp->next = current;
    }
      current = next; // Moves to the ne
  }
    *list = *sorted; // Now the start of the list points to the sorted list
}