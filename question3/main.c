#include <stdio.h>
#include "mst.h"

int main(void) {
    int n;
    int adj[MAXV][MAXV];

    printf("Enter number of hubs (vertices, max %d): ", MAXV);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAXV) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter adjacency matrix of installation costs (0 = no direct connection):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    kruskalMST(n, adj);

    return 0;
}

