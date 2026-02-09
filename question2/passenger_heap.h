#ifndef PASSENGER_HEAP_H
#define PASSENGER_HEAP_H

#define MAX_PASSENGERS 50
#define NAME_LEN 32

typedef struct {
    char name[NAME_LEN];
    int risk;
} Passenger;

typedef struct {
    Passenger arr[MAX_PASSENGERS];
    int size;
} MaxHeap;

void initHeap(MaxHeap *heap);
void buildHeap(MaxHeap *heap);
void insertPassenger(MaxHeap *heap, Passenger p);
Passenger extractMax(MaxHeap *heap);
void removeByRisk(MaxHeap *heap, int risk);
void displayHeap(const MaxHeap *heap);
void displayPriorityQueueOrder(const MaxHeap *heap);

#endif

