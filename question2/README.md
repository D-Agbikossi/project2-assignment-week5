# Smart Airport Security – Max-Heap of Passengers (Question 2)

# Project Overview

This project simulates a smart airport security control system using a Max-Heap data structure implemented in C.
Each passenger is assigned a risk score, and the system always processes the passenger with the highest risk first.

The heap is implemented using an array-based binary heap, ensuring fast insertion and deletion operations.

# Objectives

The program demonstrates how to:
- Build a binary tree from an initial list of passenger risk scores
- Convert the binary tree into a Max-Heap
- Associate each heap node with a passenger name and risk score
- Extract a priority queue (screening order) from the Max-Heap
- Insert a new high-risk passenger (risk score 98)
- Remove the passenger with risk score 98
- Maintain the Max-Heap property after every operation

# Data Structures Used

- Passenger Structure  
Each passenger contains:
    - Name (string)
    - Risk score (integer value)

- Max-Heap Structure  
The heap is stored as an array of `Passenger` items representing a complete binary tree, along with a current `size` field.

# Heap Operations Implemented

- `buildHeap()` – Converts the initial binary tree (array of passengers) into a Max-Heap  
- `insertPassenger()` – Inserts a new passenger while preserving heap order  
- `extractMax()` – Removes and returns the passenger with the highest risk score  
- `removeByRisk()` – Removes a passenger matching a given risk score (e.g., 98)  
- `heapifyUp()` – Restores heap order after insertion  
- `heapifyDown()` – Restores heap order after deletion or replacement  
- `displayHeap()` – Prints the heap contents (passenger name and risk score)  
- `displayPriorityQueueOrder()` – Prints the screening order from highest to lowest risk

All heap logic is implemented in `passenger_heap.c` and declared in `passenger_heap.h`.

# Program Workflow

1. Read the number of passengers.
2. Read each passenger’s name and risk score and store them in the heap array (initial binary tree form).
3. Display the initial binary tree (array order).
4. Convert the array into a Max-Heap using `buildHeap()`.
5. Display the heap after building the Max-Heap.
6. Use `displayPriorityQueueOrder()` to show the order in which passengers will be screened (highest risk first).
7. Read the name of a new passenger and assign them a risk score of 98.
8. Insert the new passenger into the heap using `insertPassenger()`.
9. Display the heap after inserting the risk-98 passenger.
10. Remove the passenger with risk score 98 using `removeByRisk()`.
11. Display the heap after removal to verify the Max-Heap property is preserved.

# Compilation and Execution

- Compile

``` bash
gcc main.c passenger_heap.c -o passengers
```

- Run

``` bash
./passengers
```

# Sample Output (Excerpt)

Initial Binary Tree (array order):
Alice : 40  
Brian : 65  
Chen : 30  
...

After Building Max-Heap:
Brian : 65  
Alice : 40  
Chen : 30  
...

Priority queue order (highest risk first):
Brian (risk 65)  
Alice (risk 40)  
Chen (risk 30)  
...

After inserting new passenger with risk 98:
NewPassenger : 98  
Brian : 65  
Alice : 40  
...

After removing passenger with risk 98, heap returns to the previous highest-risk passenger at the root.

(Actual names and order will vary based on input and heap operations.)

# Key Features

- Array-based Max-Heap implementation for passenger risk scores  
- Modular design separating heap logic from the main program  
- Efficient priority-based screening order  
- Clear demonstration of heapify operations during insertion and deletion  
- Easy to extend to other priority-based scheduling problems

# Concepts Demonstrated

- Binary Heaps  
- Priority Queues  
- Heapify operations (`heapifyUp`, `heapifyDown`)  
- Modular programming in C (header/source separation)  
- Array-based tree representations
