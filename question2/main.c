#include <stdio.h>
#include "passenger_heap.h"

int main(void) {
    MaxHeap heap;
    initHeap(&heap);

    int n;
    printf("Enter number of passengers (max %d): ", MAX_PASSENGERS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_PASSENGERS) {
        printf("Invalid number of passengers.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Passenger p;
        printf("\nEnter name for passenger %d: ", i + 1);
        scanf("%s", p.name);
        printf("Enter risk score for %s: ", p.name);
        scanf("%d", &p.risk);
        heap.arr[heap.size++] = p; /* initial array-based binary tree */
    }

    printf("\nInitial Binary Tree (array order):\n");
    displayHeap(&heap);

    buildHeap(&heap);
    printf("After Building Max-Heap:\n");
    displayHeap(&heap);

    displayPriorityQueueOrder(&heap);

    Passenger newP;
    printf("Enter name of new passenger with risk score 98: ");
    scanf("%s", newP.name);
    newP.risk = 98;
    insertPassenger(&heap, newP);
    printf("\nAfter inserting passenger %s with risk 98:\n", newP.name);
    displayHeap(&heap);

    removeByRisk(&heap, 98);
    printf("After removing passenger with risk 98:\n");
    displayHeap(&heap);

    return 0;
}

