#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#define MAXV 20
#define MAXE 100

typedef struct {
    int u, v;
    int w;
} Edge;

/* Runs Bellman–Ford from source on the given edge list.
 * Prints shortest paths and costs, or reports negative cycles.
 */
void bellmanFord(int V, int E, Edge edges[], int source);

#endif

