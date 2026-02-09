#include <stdio.h>
#include <ctype.h>
#include "bfs.h"

int main(void) {
    int n;
    int adj[MAXV][MAXV];

    printf("Enter number of workstations (n,max %d): ", MAXV);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAXV) {
        printf("Invalid number of workstations.\n");
        return 1;
    }

    printf("Assume workstations are labeled A, B, C, ...\n");
    printf("Enter adjacency matrix of data transfer times (matrix nxn, 0 = no direct session):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    char startLabel;
    printf("Enter suspected compromised workstation label (e.g., A): ");
    scanf(" %c", &startLabel);
    startLabel = (char)toupper((unsigned char)startLabel);
    int start = startLabel - 'A';

    if (start < 0 || start >= n) {
        printf("Invalid start workstation.\n");
        return 1;
    }

    bfsAnalyze(n, adj, start);

    return 0;
}

