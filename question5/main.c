#include <stdio.h>
#include <ctype.h>
#include "bellman_ford.h"

int main(void) {
    int V, E;
    Edge edges[MAXE];

    printf("Enter number of branches (vertices, max %d): ", MAXV);
    if (scanf("%d", &V) != 1 || V <= 0 || V > MAXV) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter number of transaction channels (edges, max %d): ", MAXE);
    if (scanf("%d", &E) != 1 || E < 0 || E > MAXE) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Assume branches are labeled A, B, C, ...\n");
    printf("For each edge, enter: from to weight (e.g., A C 5):\n");
    for (int i = 0; i < E; i++) {
        char fromLabel, toLabel;
        int w;
        scanf(" %c %c %d", &fromLabel, &toLabel, &w);
        fromLabel = (char)toupper((unsigned char)fromLabel);
        toLabel = (char)toupper((unsigned char)toLabel);
        int u = fromLabel - 'A';
        int v = toLabel - 'A';
        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid branch label in edge %d, skipping.\n", i + 1);
            i--;
            E--;
            continue;
        }
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    /* Branch A as source (index 0) */
    bellmanFord(V, E, edges, 0);

    return 0;
}

