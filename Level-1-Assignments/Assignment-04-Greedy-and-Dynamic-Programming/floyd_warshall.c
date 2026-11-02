#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define INF 1000000000

int main() {
    int V;
    if (scanf("%d", &V) != 1) return 0;

    // Use a long long or long for the distance matrix to prevent overflow 
    // when adding INF + INF, though the logic below handles it.
    long dist[V][V];

    // Input the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            char val[20];
            scanf("%s", val);
            if (strcmp(val, "INF") == 0) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = atol(val);
            }
        }
    }

    // Floyd-Warshall Triple Loop
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If path through k is shorter, update it
                // We check dist[i][k] and dist[k][j] != INF to avoid overflow additions
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Output the final shortest distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF");
            } else {
                printf("%ld", dist[i][j]);
            }
            if (j < V - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
