#ifndef HEAP_H
#define HEAP_H

#define MAX 20

/* Job structure */
typedef struct {
    char id;
    int priority;
} Job;

/* Max Heap structure */
typedef struct {
    Job arr[MAX];
    int size;
} MaxHeap;

/* Heap operations */
void initHeap(MaxHeap *heap);
void buildHeap(MaxHeap *heap);

void insertJob(MaxHeap *heap, Job job);
void removeJob(MaxHeap *heap, int priority);

void displayHeap(const MaxHeap *heap);

#endif