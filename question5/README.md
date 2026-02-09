# Banking Transaction Network – Bellman–Ford (Question 5)

# Project Overview

This project models a national bank’s inter-branch transaction system as a weighted directed graph.
Each branch is a node, and each directed edge represents a transaction channel with an associated cost or risk factor.

Starting from the central clearing branch (Branch A), the program uses the Bellman–Ford algorithm to compute minimum cumulative transaction costs to all other branches and to detect any negative-weight cycles that may indicate unstable or exploitable transaction routes.

# Objectives

The program demonstrates how to:
- Model an inter-branch transaction network as a weighted directed graph
- Represent edges with source, destination, and weight (cost/risk)
- Apply the Bellman–Ford algorithm from a single source (Branch A)
- Detect and report negative-weight cycles in the network
- Compute and display shortest paths and minimum cumulative costs from Branch A to each branch

# Data Structures Used

- Edge Structure  
Each directed transaction channel is represented by:
    - `u` – source branch index
    - `v` – destination branch index
    - `w` – transaction cost or risk factor (edge weight)

- Distance Array  
`dist[]` stores the current best-known cost from Branch A to each branch.

- Parent Array  
`parent[]` stores the predecessor of each branch on the shortest path from Branch A, allowing path reconstruction.

# Algorithms Implemented

- Bellman–Ford Algorithm  
    - Initializes all distances to infinity except the source (Branch A) which is 0.  
    - Repeatedly relaxes all edges `V - 1` times for `V` branches.  
    - Checks all edges one more time to detect negative-weight cycles.

- Shortest Path Reconstruction  
    - Uses the `parent[]` array to print full paths from Branch A to each reachable branch.

All algorithm logic is implemented in `bellman_ford.c` and declared in `bellman_ford.h`.

# Program Workflow

1. Read the number of branches `V`.
2. Read the number of transaction channels `E`.
3. Assume branches are labeled `A`, `B`, `C`, ...
4. For each of the `E` edges, read:
   - Source branch label, destination branch label, and weight (e.g., `A C 5`).
5. Store each transaction channel in an array of `Edge` structures.
6. Call `bellmanFord(V, E, edges, 0)` with Branch A as the source (index 0):
   - Relax all edges and compute minimum costs.
   - Check for negative-weight cycles.
7. If a negative-weight cycle is detected:
   - Print a warning indicating unstable or exploitable routes.
8. Otherwise:
   - For each branch, print the shortest path from Branch A and the corresponding minimum cumulative cost.

# Compilation and Execution

- Compile

``` bash
gcc main.c bellman_ford.c -o bellman
```

- Run

``` bash
./bellman

# Sample Output (Excerpt)

Shortest transaction paths from Branch A:  
Branch A to Branch A: cost = 0, path = A  
Branch A to Branch B: cost = 4, path = A B  
Branch A to Branch C: cost = 7, path = A D C  
...

If a negative-weight cycle exists, the program instead prints a warning message and does not trust the computed distances.

(Actual paths and costs will depend on the input transaction network.)

# Key Features

- Full Bellman–Ford implementation with negative-cycle detection  
- Clear edge-based graph input using branch labels  
- Detailed path and cost reporting for each branch  
- Modular separation of algorithm logic from input/output code

# Concepts Demonstrated

- Single-source shortest paths in weighted directed graphs  
- Bellman–Ford algorithm and relaxation steps  
- Negative-weight cycle detection  
- Path reconstruction from predecessor information  
- Modular programming in C

