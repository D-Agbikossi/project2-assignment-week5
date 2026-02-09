#include <stdio.h>
#include <string.h>
#include "passenger_heap.h"

static void swap(Passenger *a, Passenger *b) {
    Passenger tmp = *a;
    *a = *b;
    *b = tmp;
}

static void heapifyDown(MaxHeap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left].risk > heap->arr[largest].risk)
        largest = left;

    if (right < heap->size && heap->arr[right].risk > heap->arr[largest].risk)
        largest = right;

    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

static void heapifyUp(MaxHeap *heap, int i) {
    int parent = (i - 1) / 2;

    if (i > 0 && heap->arr[i].risk > heap->arr[parent].risk) {
        swap(&heap->arr[i], &heap->arr[parent]);
        heapifyUp(heap, parent);
    }
}

void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

void buildHeap(MaxHeap *heap) {
    for (int i = (heap->size / 2) - 1; i >= 0; i--)
        heapifyDown(heap, i);
}

void insertPassenger(MaxHeap *heap, Passenger p) {
    if (heap->size >= MAX_PASSENGERS) {
        printf("Heap overflow, cannot insert more passengers.\n");
        return;
    }

    heap->arr[heap->size] = p;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

Passenger extractMax(MaxHeap *heap) {
    Passenger dummy;
    strcpy(dummy.name, "NONE");
    dummy.risk = -1;

    if (heap->size <= 0) {
        printf("Heap underflow.\n");
        return dummy;
    }

    Passenger max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}

void removeByRisk(MaxHeap *heap, int risk) {
    int index = -1;
    for (int i = 0; i < heap->size; i++) {
        if (heap->arr[i].risk == risk) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Passenger with risk score %d not found in heap.\n", risk);
        return;
    }

    heap->arr[index] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, index);
    heapifyUp(heap, index);
}

void displayHeap(const MaxHeap *heap) {
    printf("Current Max-Heap (Passenger : Risk):\n");
    for (int i = 0; i < heap->size; i++) {
        printf("%s : %d\n", heap->arr[i].name, heap->arr[i].risk);
    }
    printf("\n");
}

void displayPriorityQueueOrder(const MaxHeap *original) {
    MaxHeap temp = *original; /* make a copy so original heap is preserved */

    printf("Priority queue order (highest risk first):\n");
    while (temp.size > 0) {
        Passenger p = extractMax(&temp);
        printf("%s (risk %d)\n", p.name, p.risk);
    }
    printf("\n");
}

