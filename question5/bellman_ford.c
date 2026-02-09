#include <stdio.h>
#include <limits.h>
#include "bellman_ford.h"

#define INF INT_MAX

static void printPath(int parent[], int v) {
    if (v == -1)
        return;
    printPath(parent, parent[v]);
    printf("%c ", 'A' + v);
}

void bellmanFord(int V, int E, Edge edges[], int source) {
    int dist[MAXV];
    int parent[MAXV];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    /* Bellman–Ford relaxation */
    for (int i = 1; i <= V - 1; i++) {
        int updated = 0;
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = 1;
            }
        }
        if (!updated)
            break;
    }

    /* Check for negative-weight cycles */
    int hasNegativeCycle = 0;
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("\nWARNING: Negative-weight cycle detected in the transaction network.\n");
        printf("This indicates potentially exploitable or unstable transaction routes.\n");
    } else {
        printf("\nShortest transaction paths from Branch A:\n");
        for (int i = 0; i < V; i++) {
            printf("Branch A to Branch %c: ", 'A' + i);
            if (dist[i] == INF) {
                printf("No path.\n");
            } else {
                printf("cost = %d, path = ", dist[i]);
                printPath(parent, i);
                printf("\n");
            }
        }
    }
}

