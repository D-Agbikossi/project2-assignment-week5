# Fiber-Optic Network – Kruskal’s MST (Question 3)

# Project Overview

This project models a fiber-optic backbone network between smart city hubs as an undirected weighted graph.
Each hub is a node, and each edge weight represents the installation cost of laying fiber between two hubs.

Kruskal’s Algorithm is used to compute a Minimum Spanning Tree (MST) that connects all hubs with the minimum total installation cost while avoiding cycles.

# Objectives

The program demonstrates how to:
- Model a fiber-optic network as an adjacency matrix
- Convert the adjacency matrix into an edge list
- Apply Kruskal’s Algorithm to build a Minimum Spanning Tree
- Use a Disjoint Set / Union-Find data structure to detect cycles
- List the selected fiber-optic links in the MST
- Compute and display the total installation cost of the MST

# Data Structures Used

- Adjacency Matrix  
Stores installation costs between hubs in a 2D array:
    - Rows and columns represent hubs.
    - A value of `0` indicates no direct connection.

- Edge Structure  
Each edge contains:
    - `u` – index of the first hub
    - `v` – index of the second hub
    - `w` – installation cost (edge weight)

- Disjoint Set / Union-Find  
Two arrays are used:
    - `parent[]` – parent representative for each hub
    - `rank[]` – rank/height used for union by rank

# Algorithms Implemented

- Kruskal’s Algorithm  
    - Sorts all edges by non-decreasing weight.  
    - Iterates through edges, adding an edge to the MST if it connects two different sets (no cycle).  
    - Stops when `n - 1` edges have been added for `n` hubs.

- Disjoint Set / Union-Find  
    - `makeSet()` – initializes each hub as its own set  
    - `findSet()` – finds the representative of a set with path compression  
    - `unionSets()` – merges two sets using union by rank

All MST logic is implemented in `mst.c` and declared in `mst.h`.

# Program Workflow

1. Read the number of hubs (vertices) `n`.
2. Read an `n x n` adjacency matrix of installation costs:
   - `0` indicates no direct link.
   - Positive values indicate fiber installation cost.
3. Call `kruskalMST(n, adj)` to:
   - Build an edge list from the upper triangle of the matrix.
   - Sort the edges by weight.
   - Use Union-Find to construct the MST.
4. Print each selected MST edge in the form `A - C : 5`.
5. Print the total installation cost of the MST.
6. If the graph is disconnected (no spanning tree), report that an MST spanning all hubs does not exist.

# Compilation and Execution

- Compile

``` bash
gcc main.c mst.c -o q3_mst
```

- Run

``` bash
./q3_mst        # on Linux / macOS
q3_mst.exe      # on Windows
```

# Sample Output (Excerpt)

Selected fiber-optic links for MST:
A - C : 4  
C - D : 5  
A - B : 7  
...

Total installation cost of MST: 23

(Actual edges and total cost will depend on the input adjacency matrix.)

# Key Features

- Clear modeling of a weighted undirected graph using an adjacency matrix  
- Kruskal’s MST implementation with a modular design  
- Safe cycle detection via Disjoint Set / Union-Find  
- Human-readable output showing selected links and total cost

# Concepts Demonstrated

- Minimum Spanning Trees  
- Kruskal’s Algorithm  
- Disjoint Set / Union-Find (path compression and union by rank)  
- Graph representation with adjacency matrices  
- Modular programming in C

