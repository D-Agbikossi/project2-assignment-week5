#include <stdio.h>
#include "mst.h"

static int parent[MAXV];
static int rankArr[MAXV];

static void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

static int findSet(int v) {
    if (v == parent[v])
        return v;
    parent[v] = findSet(parent[v]); /* path compression */
    return parent[v];
}

static void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rankArr[a] < rankArr[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        parent[b] = a;
        if (rankArr[a] == rankArr[b])
            rankArr[a]++;
    }
}

static void sortEdges(Edge edges[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge tmp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = tmp;
            }
        }
    }
}

int kruskalMST(int n, int adj[MAXV][MAXV]) {
    Edge edges[MAXE];
    int m = 0;

    /* Build edge list from upper triangle of adjacency matrix (undirected graph) */
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] != 0) {
                edges[m].u = i;
                edges[m].v = j;
                edges[m].w = adj[i][j];
                m++;
            }
        }
    }

    if (m == 0) {
        printf("No edges in the graph.\n");
        return -1;
    }

    sortEdges(edges, m);
    makeSet(n);

    int mstCost = 0;
    int edgesUsed = 0;

    printf("\nSelected fiber-optic links for MST:\n");
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (findSet(u) != findSet(v)) {
            unionSets(u, v);
            mstCost += w;
            edgesUsed++;
            printf("%c - %c : %d\n", 'A' + u, 'A' + v, w);
            if (edgesUsed == n - 1)
                break;
        }
    }

    if (edgesUsed != n - 1) {
        printf("\nGraph is not connected; MST cannot span all hubs.\n");
        return -1;
    } else {
        printf("\nTotal installation cost of MST: %d\n", mstCost);
        return mstCost;
    }
}

