#ifndef BFS_H
#define BFS_H

#define MAXV 30

/* Performs BFS from start vertex index and analyzes
 * direct neighbors to find the highest data transfer time.
 */
void bfsAnalyze(int n, int adj[MAXV][MAXV], int start);

#endif

