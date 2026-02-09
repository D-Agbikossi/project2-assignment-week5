#ifndef MST_H
#define MST_H

#define MAXV 20
#define MAXE (MAXV * MAXV)

typedef struct {
    int u, v;
    int w;
} Edge;

/* Runs Kruskal's algorithm on the given adjacency matrix.
 * Prints selected MST edges and total cost.
 * Returns total cost if an MST spanning all vertices exists, -1 otherwise.
 */
int kruskalMST(int n, int adj[MAXV][MAXV]);

#endif

