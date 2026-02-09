# Enterprise Communication Graph – BFS Analysis (Question 4)

# Project Overview

This project models an enterprise communication network as a graph of workstations.
Each workstation is a node, and an edge between two nodes represents a direct network session with an associated total data transfer time.

Given a suspected compromised workstation, the program uses Breadth-First Search (BFS) to explore the network and analyze which directly connected workstation has the highest risk of exposure.

# Objectives

The program demonstrates how to:
- Represent a communication graph using an adjacency matrix
- Perform Breadth-First Search (BFS) from a chosen starting node
- Discover all directly connected (one-hop) neighbors of the suspected workstation
- Analyze edge weights (data transfer times) to identify the highest-risk neighbor
- Present BFS traversal order and neighbor analysis in a clear format

# Data Structures Used

- Adjacency Matrix  
Stores total data transfer times in a 2D array:
    - Rows and columns represent workstations labeled `A`, `B`, `C`, ...
    - A value of `0` indicates no direct session.

- Queue for BFS  
An array-based queue with:
    - `enqueue()` / `dequeue()` operations
    - `front` and `back` indices to manage BFS order

- Visited Array  
An integer array `visited[]` marks which workstations have already been visited during BFS.

# Algorithms Implemented

- Breadth-First Search (BFS)  
    - Starts from the suspected workstation.  
    - Visits nodes level by level using the queue.  
    - Ensures each workstation is visited at most once.

- Neighbor Risk Analysis  
    - After BFS, directly examines the row of the starting workstation in the adjacency matrix.  
    - Lists all one-hop neighbors and their data transfer times.  
    - Finds the neighbor with the maximum data transfer time (highest exposure).

All BFS and analysis logic is implemented in `bfs.c` and declared in `bfs.h`.

# Program Workflow

1. Read the number of workstations `n`.
2. Read an `n x n` adjacency matrix of data transfer times:
   - `0` = no direct communication.
   - Positive values = total data transfer time (minutes).
3. Assume workstation labels are `A`, `B`, `C`, ...
4. Read the label of the suspected compromised workstation (e.g., `A`).
5. Convert the label to an index and call `bfsAnalyze(n, adj, startIndex)`:
   - Perform BFS traversal and print the order of visited workstations.
   - List all direct neighbors and their edge weights.
   - Identify and print the neighbor with the highest transfer time.

# Compilation and Execution

- Compile

``` bash
gcc main.c bfs.c -o bfs
```

- Run

``` bash
./bfs
```

# Sample Output (Excerpt)

BFS traversal starting from A:  
A B D C ...

Directly connected workstations to A (one-hop neighbors):  
A --(5 minutes)--> B  
A --(12 minutes)--> D  
...

Highest risk direct exposure from A is workstation D with data transfer time 12 minutes.

(Actual traversal and times will depend on the input communication graph.)

# Key Features

- BFS-based exploration of a weighted communication graph  
- Identification of highest-risk direct neighbor based on data transfer time  
- Simple adjacency-matrix input format matching the given diagram  
- Modular separation between BFS logic and user interaction

# Concepts Demonstrated

- Graph traversal with Breadth-First Search  
- Adjacency matrix representation of graphs  
- Simple risk analysis using edge weights  
- Modular programming in C

