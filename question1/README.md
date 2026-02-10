# Max-Heap Job Scheduler (Question 1)

# Project Overview

This project simulates a cloud computing job scheduler using a Max-Heap data structure implemented in C.
Each incoming job is assigned a priority score, and the scheduler always executes the job with the highest priority first.

The heap is implemented using an array-based binary heap, ensuring fast insertion and deletion operations.

# Objectives

The program demonstrates how to:
- Build a binary tree from an array of job priorities
- Convert the binary tree into a Max-Heap
- Assign unique job identifiers to each job
- Insert a high-priority (urgent) job
- Remove a specific job from the heap
- Maintain the Max-Heap property after every operation

# Data Structures Used
- Job Structure
Each job contains:
    - Job ID (single uppercase character)
    - Priority (integer value)

- The heap is stored as an array representing a complete binary tree.

# Heap Operations Implemented

- buildHeap() – Converts a binary tree into a Max-Heap
- insertJob() – Inserts a new job while preserving heap order
- removeJob() – Removes a job by priority
- heapifyUp() – Restores heap after insertion
- heapifyDown() – Restores heap after deletion
- displayHeap() – Prints the heap contents

# Program Workflow

1. Insert initial job priorities into the heap
2. Display the initial binary tree (array form)
3. Convert the tree into a Max-Heap
4. Insert an urgent job with priority 100
5. Re-adjust the heap
6. Remove the urgent job
7. Re-adjust the heap again
8. Display heap after each major operation

# Compilation and Execution
- Compile

``` bash
gcc main.c heap.c -o scheduler
```


- Run

```bash
./scheduler
```

# Sample Output (Excerpt)
Initial Binary Tree (array-based complete binary tree printed by level):
Level 0: (A,42)
Level 1: (B,17) (C,93)
Level 2: (D,28) (E,65) (F,81) (G,54)
Level 3: (H,60) (I,99) (J,73) (K,88)

After Building Max-Heap:
Level 0: (I,99)
Level 1: (K,88) (C,93)
Level 2: (H,60) (J,73) (F,81) (G,54)
Level 3: (B,17) (D,28) (A,42) (E,65)

After Inserting Urgent Job (L,100):
Level 0: (L,100)
Level 1: (K,88) (I,99)
Level 2: (H,60) (J,73) (C,93) (G,54)
Level 3: (B,17) (D,28) (A,42) (E,65) (F,81)

After Removing Urgent Job (priority 100):
Level 0: (I,99)
Level 1: (K,88) (C,93)
Level 2: (H,60) (J,73) (F,81) (G,54)
Level 3: (B,17) (D,28) (A,42) (E,65)

(Exact level contents may vary slightly if you change the input array, but the root will always have the highest priority and each level will respect the Max-Heap property.)

# Key Features

- Array-based Max-Heap implementation
- Modular and reusable design
- Efficient priority scheduling
- Clear demonstration of heap operations
- Well-structured and documented code

# Concepts Demonstrated

- Binary Heaps
- Priority Queues
- Heapify operations
- Modular programming in C
- Data structure optimization