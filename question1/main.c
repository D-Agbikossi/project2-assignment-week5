#include <stdio.h>
#include "heap.h"

int main() {
    int priorities[] = {42, 17, 93, 28, 65, 81, 54, 60, 99, 73, 88};
    int n = sizeof(priorities) / sizeof(priorities[0]);

    MaxHeap heap;
    initHeap(&heap);

    /* Insert initial jobs */
    for (int i = 0; i < n; i++) {
        Job job;
        job.id = 'A' + i;
        job.priority = priorities[i];
        heap.arr[heap.size++] = job;
    }

    printf("Initial Binary Tree:\n");
    displayHeap(&heap);

    buildHeap(&heap);
    printf("After Building Max-Heap:\n");
    displayHeap(&heap);

    Job urgent = {'L', 100};
    insertJob(&heap, urgent);
    printf("After Inserting Urgent Job:\n");
    displayHeap(&heap);

    removeJob(&heap, 100);
    printf("After Removing Urgent Job:\n");
    displayHeap(&heap);

    return 0;
}