#include <stdio.h>
#include "bfs.h"

static int queueArr[MAXV];
static int frontIdx = 0, backIdx = 0;

static void resetQueue(void) {
    frontIdx = backIdx = 0;
}

static int isEmpty(void) {
    return frontIdx == backIdx;
}

static void enqueue(int v) {
    queueArr[backIdx++] = v;
}

static int dequeue(void) {
    return queueArr[frontIdx++];
}

void bfsAnalyze(int n, int adj[MAXV][MAXV], int start) {
    int visited[MAXV] = {0};
    char startLabel = (char)('A' + start);

    resetQueue();
    visited[start] = 1;
    enqueue(start);

    printf("\nBFS traversal starting from %c:\n", startLabel);
    while (!isEmpty()) {
        int u = dequeue();
        printf("%c ", 'A' + u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
    printf("\n\n");

    /* Analyze direct neighbors (one-hop) from suspected workstation */
    int hasNeighbor = 0;
    int maxTime = -1;
    int maxNeighbor = -1;

    printf("Directly connected workstations to %c (one-hop neighbors):\n", startLabel);
    for (int v = 0; v < n; v++) {
        int time = adj[start][v];
        if (time != 0) {
            hasNeighbor = 1;
            printf("%c --(%d minutes)--> %c\n", startLabel, time, 'A' + v);
            if (time > maxTime) {
                maxTime = time;
                maxNeighbor = v;
            }
        }
    }

    if (!hasNeighbor) {
        printf("No directly connected workstations found for %c.\n", startLabel);
    } else {
        printf("\nHighest risk direct exposure from %c is workstation %c with data transfer time %d minutes.\n",
               startLabel, 'A' + maxNeighbor, maxTime);
    }
}

