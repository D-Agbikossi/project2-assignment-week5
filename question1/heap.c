#include <stdio.h>
#include "heap.h"

/* Swap two jobs */
static void swap(Job *a, Job *b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify down */
static void heapifyDown(MaxHeap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size &&
        heap->arr[left].priority > heap->arr[largest].priority)
        largest = left;

    if (right < heap->size &&
        heap->arr[right].priority > heap->arr[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

/* Heapify up */
static void heapifyUp(MaxHeap *heap, int i) {
    int parent = (i - 1) / 2;

    if (i > 0 &&
        heap->arr[i].priority > heap->arr[parent].priority) {
        swap(&heap->arr[i], &heap->arr[parent]);
        heapifyUp(heap, parent);
    }
}

/* Initialize heap */
void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

/* Build Max-Heap */
void buildHeap(MaxHeap *heap) {
    for (int i = (heap->size / 2) - 1; i >= 0; i--)
        heapifyDown(heap, i);
}

/* Insert job */
void insertJob(MaxHeap *heap, Job job) {
    if (heap->size >= MAX) {
        printf("Heap overflow!\n");
        return;
    }

    heap->arr[heap->size++] = job;
    heapifyUp(heap, heap->size - 1);
}

/* Remove job by priority */
void removeJob(MaxHeap *heap, int priority) {
    int index = -1;

    for (int i = 0; i < heap->size; i++) {
        if (heap->arr[i].priority == priority) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Job with priority %d not found.\n", priority);
        return;
    }

    heap->arr[index] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, index);
    heapifyUp(heap, index);
}

/* Display heap as a tree (level-order) */
void displayHeap(const MaxHeap *heap) {
    printf("Heap as tree (JobID:Priority by level)\n");

    int level = 0;
    int itemsOnLevel = 0;
    int capacityThisLevel = 1; /* 2^level */

    for (int i = 0; i < heap->size; i++) {
        if (itemsOnLevel == 0) {
            printf("Level %d: ", level);
        }

        printf("(%c,%d) ", heap->arr[i].id, heap->arr[i].priority);
        itemsOnLevel++;

        if (itemsOnLevel == capacityThisLevel) {
            printf("\n");
            level++;
            itemsOnLevel = 0;
            capacityThisLevel *= 2;
        }
    }

    if (itemsOnLevel != 0) {
        printf("\n");
    }

    printf("\n");
}