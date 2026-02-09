# Data Structures & Algorithms Project – Week 5

## Project Overview

This project contains five independent C programs, each solving a different real-world inspired problem using classic data structures and algorithms:

- **Question 1** – Max-Heap based job scheduler in a cloud environment  
- **Question 2** – Max-Heap of passengers for smart airport security  
- **Question 3** – Kruskal’s algorithm for a fiber-optic Minimum Spanning Tree  
- **Question 4** – BFS-based communication graph analysis for a cyber incident  
- **Question 5** – Bellman–Ford shortest paths for a banking transaction network

Each question is implemented in its own subfolder with a modular structure (`.h`/`.c` files) and a dedicated `README.md` explaining details and usage.

## Folder Structure

- `question1/`
  - `main.c` – Driver program for the job scheduler
  - `heap.c` / `heap.h` – Array-based Max-Heap implementation for jobs
  - `README.md` – Detailed documentation for Question 1

- `question2/`
  - `main.c` – Driver program for passenger risk scheduling
  - `passenger_heap.c` / `passenger_heap.h` – Max-Heap of passengers (name + risk)
  - `README.md` – Documentation for Question 2

- `question3/`
  - `main.c` – Driver program for running Kruskal’s algorithm
  - `mst.c` / `mst.h` – Minimum Spanning Tree logic using Union-Find
  - `README.md` – Documentation for Question 3

- `question4/`
  - `main.c` – Driver program for BFS and neighbor risk analysis
  - `bfs.c` / `bfs.h` – BFS traversal and direct neighbor analysis
  - `README.md` – Documentation for Question 4

- `question5/`
  - `main.c` – Driver program for Bellman–Ford shortest paths
  - `bellman_ford.c` / `bellman_ford.h` – Bellman–Ford implementation and path reporting
  - `README.md` – Documentation for Question 5

## Compilation

All code is written in standard C and can be compiled with `gcc` from within each question’s folder.

Examples (run these inside each `questionX` directory):

- **Question 1**
  ```bash
  gcc main.c heap.c -o q1_scheduler
  ```

- **Question 2**
  ```bash
  gcc main.c passenger_heap.c -o q2_passengers
  ```

- **Question 3**
  ```bash
  gcc main.c mst.c -o q3_mst
  ```

- **Question 4**
  ```bash
  gcc main.c bfs.c -o q4_bfs
  ```

- **Question 5**
  ```bash
  gcc main.c bellman_ford.c -o q5_bellman
  ```

On Windows you will get `.exe` files (for example, `q1_scheduler.exe`).

## Execution

After compiling, run the executables from within their respective folders:

```bash
./q1_scheduler     # or q1_scheduler.exe on Windows
./q2_passengers
./q3_mst
./q4_bfs
./q5_bellman
```

Each program will prompt for the necessary input (arrays, adjacency matrices, or edge lists) based on the corresponding problem statement. For more detailed instructions and example outputs, see the `README.md` file inside each `questionX` directory.
